#include <sstream>
#include "movie.h"
#include "util.h"

using namespace std;


Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating) :
	Product(category, name, price, qty){
	genre_ = genre;
	rating_ = rating;
}

Movie::~Movie() {}


//genre and name keywords
std::set<std::string> Movie::keywords() const {
	std::set<std::string> genreKeywords = parseStringToWords(genre_);
	std::set<std::string> nameKeywords = parseStringToWords(name_);

	return setUnion(genreKeywords, nameKeywords);
}

//return genre
std::string Movie::getGenre() const {return genre_;}


//return rating
std::string Movie::getRating() const {return rating_;}

//display string of requirements of the movie
std::string Movie::displayString() const {
	return (name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + std::to_string(price_)+ " "
            + std::to_string(qty_) + " left.");}

bool Movie::isMatch(std::vector<std::string>& searchTerms) const { return false; }

//output dump
void Movie::dump(std::ostream& os) const {
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << std::endl;
}