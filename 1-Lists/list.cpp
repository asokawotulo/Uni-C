#include <iostream>
#include <iomanip>
#include <string>
#include <list>
using namespace std;
struct Book{
	int id;
	string name;
	int qty;
};
void insert(list<Book>* b_list, string i_name, int i_qty){
	Book input;
	input.id = b_list->empty()?1:b_list->back().id+1;
	input.name = i_name;
	input.qty = i_qty;
	b_list->push_back(input);
}
void purchase(list<Book>* b_list, int index, int amount){
	list<Book>::iterator i;
	Book book;
	bool found = false;
	for(i=b_list->begin(); i!=b_list->end(); i++){
		if(i->id == index){
			book = *i;
			found = true;
			break;
		}
	}
	if(book.qty >= amount && found){
		book.qty -= amount;
		(*i) = book;
		cout << amount << " \"" << book.name << "\" " << "books bought" << endl;
	} else if(book.qty < amount && found){
		cout << "Insufficient number of books" << endl;
	} else if(!found){
		cout << "Book not found" << endl;
	}
}
void restock(list<Book>* b_list, int index, int amount){
	list<Book>::iterator i;
	for(i=b_list->begin(); i!=b_list->end(); i++){
		if(i->id == index){
			i->qty += amount;
			cout << amount << " \"" << i->name << "\" " << "books added" << endl;
			break;
		}
	}
}
void print(list<Book> b_list){
	list<Book>::iterator i;
	for (i=b_list.begin(); i!=b_list.end(); i++){
		Book entry = *i;
		cout << "-------------------------------" << endl;
		cout << "ID:       " << entry.id << endl << "Name:     " << entry.name << endl << "Quantity: " << entry.qty << endl;
	}
	cout << "-------------------------------" << endl;
}
int options(){
	int option = 0;
	cout << "Options..." << endl << "[1] Add new book" << endl << "[2] Purchase book" << endl << "[3] Restock books" << endl << "[4] Show all books" << endl << "[5] End program" << endl;
	cin >> option;
	return option;
}
int main(){
	list<Book> book_list;
	int index;
	int amount;
	string i_name;
	int i_qty;
	int option = 0;

	while(option != 5){
		switch(option){
			case 1:
				cout << "Name: ";
				cin >> i_name;
				cout << "Quantity: ";
				cin >> i_qty;
				insert(&book_list, i_name, i_qty);
				break;
			case 2:
				cout << "ID: ";
				cin >> index;
				cout << "Amount: ";
				cin >> amount;
				purchase(&book_list, index, amount);
				break;
			case 3:
				cout << "ID: ";
				cin >> index;
				cout << "Amount: ";
				cin >> amount;
				restock(&book_list, index, amount);
				break;
			case 4:
				print(book_list);
				break;
		}
		option = options();
	}
	return 0;
}