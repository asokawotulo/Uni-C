#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Book.h"
#include "linkedlist.h"
using namespace std;

int main(){

	List<Book> booklist;
	List<Book>::iterator iterbook;
	iterbook = booklist.begin();
	cout << "A Ridiculously Simple Library" << endl;
	cout << "=============================" << endl << endl;
	// adding books	
	Book b1(515, "The Flying Fox", "Martha");
	Book b2(414, "The Flying Ant", "Meghan");
	Book b3(313, "The Flying Monk", "Ellie");
	Book b4(212, "The Flying Bike", "Ed");

	booklist.insert(iterbook, b1);
	booklist.insert(iterbook, b2);
	booklist.insert(iterbook, b3);
	booklist.insert(iterbook, b4);

	// print the size of the collection
	cout << "Number of books: " << booklist.size() << endl;
	
	// print existing books
	for(iterbook=booklist.begin(); iterbook != booklist.end(); iterbook++){
		cout << *iterbook << endl;
	}
	cout << endl;
	
	//adding some more books
	Book* b5 = new Book(515, "Maggie The Fox", "Sia");
	Book* b6 = new Book(414, "John The Ant", "Leboef");
	Book* b7 = new Book(313, "Frank The Monk", "Charlie");
	Book* b8 = new Book(212, "Job The Bike", "Puth");

	iterbook = booklist.begin();
	
	booklist.insert(iterbook, *b5);
	booklist.insert(iterbook, *b6);
	booklist.insert(iterbook, *b7);
	booklist.insert(iterbook, *b8);

	// print existing books
	cout << "Number of books: " << booklist.size() << endl;

	int i=1;
	iterbook = booklist.begin();
	while (iterbook != booklist.end()){
		cout << i << ". " << *iterbook << endl;
		iterbook++;
		i++;	
	}
	cout << endl;
	
	// search for a book
	cout << "Search for John The Ant" << endl;
	List<Book>::iterator pos;
	pos = booklist.find(booklist.begin(), booklist.end(), *b6);
	if(pos != booklist.end()) {
		cout << "FOUND: " << *pos << endl<<endl;		
	}else{
		cout << "NOT FOUND." << endl<<endl;
	}
	
	// adding some more books	
	Book b9(215, "Daylight Thunder", "Swee Thiat");
	Book b10(214, "Rain Man", "Svenja Schach");
	Book b11(213, "Electric Meme", "Susan Swinburne");
	Book b12(212, "Watch out!", "Isaak Dinesen");
	
	booklist.push_back(b9);
	booklist.push_back(b10);
	booklist.push_front(b11);
	booklist.push_front(b12);
	
	// // print existing books
	cout << "Number of books: " << booklist.size() << endl;
	i=1;
	iterbook = booklist.begin();
	while (iterbook != booklist.end()){
		cout << i << ". " << *iterbook << endl;	
		iterbook++;
		i++;	
	}
	cout << endl;
	
	// print the first and the last element
	cout << "The first element: " << booklist.front() << endl;
	cout << "The last element: " << booklist.back() << endl<< endl;
	
	// delete the Rain Man Book
	cout << "Delete the Rain Man book" << endl;
	pos = booklist.find(booklist.begin(), booklist.end(), b10);
	if(pos != booklist.end()) {
		booklist.erase(pos);	
		cout << endl << endl;
	}else{
		cout << "NOT FOUND, cannot delete. " << endl<<endl;
	}
	
	// print existing books
	cout << "Number of books: " << booklist.size() << endl;

	i=1;
	iterbook = booklist.begin();
	while (iterbook != booklist.end()){
		cout << i << ". " << *iterbook << endl;	
		iterbook++;
		i++;	
	}
	cout << endl;
	
	// delete all the books
	cout << "Delete all the books." << endl;
	
	booklist.clear();
	
	// check if it is empty
	if(booklist.empty())
		cout << "Empty collection. Bye..." << endl;
}