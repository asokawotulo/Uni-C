#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Book.h"
using namespace std;

template <typename T>
struct NODE{
	T data;
	NODE* next;
	NODE() : next(nullptr) {}
	NODE(const T& item, NODE<T> *ptr = NULL) : data(item), next(ptr) {}
};
template <typename T>
class List{
	private:
		NODE<T> *head;
		NODE<T> *tail;
		int count = 0;
	public:
		List<T>(){
			tail = head = new NODE<T>();
		};

		// Iterator
		class iterator{
			friend class List;
			private:
				iterator(NODE<T> *newPtr) : nodePtr(newPtr) {}
			public:
				NODE<T> *nodePtr;
				iterator() : nodePtr(NULL) {} 
				bool operator!=(const iterator& itr) const {
					return nodePtr != itr.nodePtr;
				}
				T& operator*() const {
					return nodePtr->next->data;
				}
				iterator operator++(int) {
					iterator temp = *this;
					nodePtr = nodePtr->next;
					return temp;
				}
		};

		iterator begin(){
			return iterator(head);
		}
		iterator end(){
			return iterator(tail);
		}
		T& front(){
			return (head->next->data);
		}
		T& back(){
			return (tail->data);
		}

		iterator insert(iterator& position, const T& book) {
			NODE<T>* newNode = new NODE<T>(book, position.nodePtr->next);
			if(position.nodePtr == tail) tail = newNode;
			position.nodePtr->next = newNode;
			count++;
			position++;
			return position;
		}
		iterator push_front(const T& book) {
			iterator position = iterator(head);
			NODE<T>* newNode = new NODE<T>(book, position.nodePtr->next);
			if(position.nodePtr == tail) tail = newNode;
			position.nodePtr->next = newNode;
			count++;
			return position;
		}
		iterator push_back(const T& book) {
			iterator position = iterator(tail);
			NODE<T>* newNode = new NODE<T>(book, position.nodePtr->next);
			if(position.nodePtr == tail) tail = newNode;
			position.nodePtr->next = newNode;
			count++;
			return position;
		}
		iterator erase(iterator position) {
			NODE<T> *toDelete = position.nodePtr->next;
			position.nodePtr->next = position.nodePtr->next->next;
			if (toDelete == tail) tail = position.nodePtr;
			delete toDelete;
			count--;
			return position;
		}

		iterator find(iterator begin, iterator end, const T& book){
			for(; begin != end; begin++){
				if(*begin == book){
					return begin;
				}
			}
			return end;
		}

		void clear(){
			while (head->next != nullptr) {
				NODE<T>* temp = head;
				head = head->next;
				delete temp;
			}
			delete head;
		}

		// Size
	    size_t size() const{
		    return count;
		};
	    bool empty() const{
		    return head->next == nullptr;
		};
};

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