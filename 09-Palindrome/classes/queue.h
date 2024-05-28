template <typename T>
struct NODE{
	T data;
	NODE* next;
	NODE() : next(nullptr) {}
	NODE(const T& item, NODE<T> *ptr = NULL) : data(item), next(ptr) {}
};
template <typename T>
class Queue{
	private:
		NODE<T>* head;
		NODE<T>* tail;
		int count;
	public:
		Queue<T>(){
			count = 0;
			tail = head = new NODE<T>();
		};
		void enqueue(const T& object){
			NODE<T>* newNode = new NODE<T>(object, NULL);
			if(count == 0){
				head = newNode;
				tail = head;
			} else {
				tail->next = newNode;
				tail = newNode;
			}
			count++;
		}
		T& dequeue(){
			NODE<T>* temp = head;
			delete head;
			head = temp->next;
			count--;
			return temp->data;
		}
		T& front(){
			return head->data;
		}
		int size(){
			return count;
		}
		void print(){
			NODE<T>* current = head;
			while(current != NULL){
				std::cout << current->data << std::endl;
				current = current->next;
			}
		}
		int lessthanzero(){
			NODE<T>* current = head;
			int result = 0;
			while(current != NULL){
				if(current->data < 0){
					result++;
				}
				current = current->next;
			}
			return result;
		}
};