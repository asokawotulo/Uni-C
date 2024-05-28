#include <iostream>
#include "queue.h"
using namespace std;

template <typename T>
void copy(Queue<T> q1, Queue<T> &q2){
	while(q1.size() != 0){
		q2.enqueue(q1.dequeue());
	}
}
template <typename T>
int match(Queue<T> q1, Queue<T> q2){
	int result = 0;
	int minSize = q1.size()>q2.size()?q2.size():q1.size();
	q1.print();
	cout << endl;
	q2.print();
	// while(minSize != 0){
	// 	// cout << q1.size();
	// 	// cout << q2.size();
	// 	// if(q1.dequeue() == q2.dequeue()){
	// 	// 	result++;
	// 	// }
	// 	minSize--;
	// }
	return result;
}

int main(){
	Queue<int> queue;
	Queue<int> queue2;

	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	queue.enqueue(4);
	queue.enqueue(5);
	queue.enqueue(6);

	copy(queue, queue2);
	// queue.enqueue(1);
	queue.enqueue(1);
	// queue.dequeue();

	queue2.print();

	// cout << queue.lessthanzero() << " less than zero" << endl;
	// cout << match(queue, queue2);

	return 0;
}