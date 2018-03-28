#include <iostream>
using namespace std;

template<typename T>
struct NODE{
	T data;
	NODE<T>* link;
};

template<typename T>
class simpleLL{
	public:
		void insert(const T& item);
		void print() const;
		bool search(const T& item) const;
		void destroy();
		simpleLL();
		~simpleLL();

	private:
		NODE<T>* first;
		NODE<T>* last;
		int count;
};

template<typename T>
simpleLL::simpleLL(){
	count = 0;
	first = NULL;
	last = NULL;
}
void simpleLL::insert(){
	T entry;
	cout << "Entry: ";
	cin >> entry;
	if(count == 0){
		newnode = new NODE;
		head = newnode;
		current = head;

		current->link = NULL;
		current->id = sId;
		current->name = sName;
		current->gpa = sGpa;
	}
}