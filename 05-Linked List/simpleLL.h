#include <iostream>

template<typename T>
struct NODE{
	T data;
	NODE<T>* link;
};

template<typename T>
class simpleLL {
	public:
		void insert(const T& item);
		void print() const;
		bool search(const T& item) const;
		void destroy();
		simpleLL<T>(){
			count = 0;
			first = NULL;
			last = NULL;
		};
	private:
		NODE<T>* first;
		NODE<T>* last;
		int count;
};

template<typename T>
void simpleLL<T>::insert(const T& item){
	NODE<T> *newnode = new NODE<T>;
	newnode->data = item;
	newnode->link = NULL;

	if(count == 0){
		first = newnode;
		last = first;
	} else{
		last->link = newnode;
		last = newnode;
	}
	count++;
}
template<typename T>
void simpleLL<T>::print() const{
	NODE<T>* temp = first;
	while(temp != NULL){
		std::cout << temp->data << std::endl;
		temp = temp->link;
	}
}
template<typename T>
bool simpleLL<T>::search(const T& item) const{
	NODE<T>* temp = first;
	while(temp != NULL){
		if(temp->data == item){
			return true;
		}
		temp = temp->link;
	}
	return false;
}
template<typename T>
void simpleLL<T>::destroy(){
	NODE<T>* temp = first;
	NODE<T>* current;
	while(temp != NULL){
		current = temp;
		temp = temp->link;
		delete current;
	}
	delete temp;
}