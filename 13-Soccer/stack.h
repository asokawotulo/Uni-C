#include <iostream>
#include <string>

template <typename T>
struct NODE{
	T data;
	NODE* next;
	NODE() : next(nullptr) {}
	NODE(const T& item, NODE<T> *ptr = NULL) : data(item), next(ptr) {}
};
template <typename T>
class Stack{
	private:
		NODE<T> *top;
		int counter = 0;
	public:
		Stack<T>(){
			top = new NODE<T>();
		};
		~Stack<T>(){
			NODE<T>* temp = top;
			NODE<T>* current;
			while(temp != NULL){
				current = temp;
				temp = temp->next;
				delete current;
			}
			delete temp;
		}
		void clear(){
			for(int i = 0; i < counter; i++){
				this->pop();
			}
		}
		void push(T data){
			NODE<T> *temp = new NODE<T>(data, top);
			top = temp;
			counter++;
		}
		T pop(){
			if(counter > 0){
				NODE<T> *temp = new NODE<T>(top->data, top->next);
				delete top;
				top = temp->next;
				counter--;
				return temp->data;
			}
			return -1;
		}
		int size(){
			return counter;
		}
};