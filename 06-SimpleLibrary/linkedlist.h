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