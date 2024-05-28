#include <iostream>
#include <list>
#include <string>

using namespace std;

class Book {
	public:
		friend ostream& operator<<(ostream&, Book&);
		bool operator==(const Book&) const;
		void getBookInfo(int& callnumber, string& title, string& author ) const;
		void setBookInfo(const int& callnumber, const string& title, const string& author );
		int getCallNumber() const;
		string toString();
		Book();
		Book(int c, string t, string a);

	private:
		int callnumber;
		string title;
		string author;
};

Book::Book(){
	callnumber = 0;
	title = "";
	author = "";
}

Book::Book(int c, string t, string a){
	callnumber = c;
	title = t;
	author = a;
}

int Book::getCallNumber() const{
	return callnumber;
}

void Book::getBookInfo(int& callnumber, string& title, string& author) const {
	callnumber = this->callnumber;
	title = this->title;
	author = this->author;
}

void Book::setBookInfo(const int& callnumber, const string& title, const string& author) {
	this->callnumber = callnumber;
	this->title = title;
	this->author = author;
}

bool Book::operator==(const Book& rhs) const{
	if(this->callnumber == rhs.callnumber && this->title == rhs.title && this->author == rhs.author)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, Book& b) {
	return cout << b.callnumber << ", " << b.title << ", " << b.author;
}


