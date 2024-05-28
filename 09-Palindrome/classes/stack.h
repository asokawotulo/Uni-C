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
		void isEmpty(){
			std::cout << (counter==0?"Stack is empty":"Stack is not empty") << std::endl;
		}
		void push(T data){
			NODE<T> *temp = new NODE<T>(data, top);
			top = temp;
			counter++;
		}
		void pop(){
			if(counter > 0){
				NODE<T> *temp = new NODE<T>(top->data, top->next);
				delete top;
				top = temp->next;
				counter--;
				std::cout << "\"" << temp->data << "\" popped" << std::endl;
			} else{
				std::cout << "Nothing to pop" << std::endl;
			}
		}
		void count(){
			std::cout << "Number of data: " << counter << std::endl;
		}
		void print(){
			NODE<T> *temp = new NODE<T>(top->data, top->next);
			for(int i = 0; i<counter; i++){
				std::cout << "[" << i+1 << "] " << temp->data << std::endl;
				temp = temp->next;
			}
		}
};