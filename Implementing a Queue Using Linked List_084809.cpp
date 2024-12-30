#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class Queue {
	private:
		Node* front;
		Node* rear;
		
	public:
		Queue() : front(nullptr), rear(nullptr) {}
		
		void enqueue(int x) {
			Node* newNode = new Node();
			newNode->data = x;
			newNode->next = nullptr;
			
			if (!rear) {
				front = rear = newNode;
				return;
			}
			
			rear->next = newNode;
			rear = newNode;
			
			cout<<x<<"enqueued to queue\n";
		}
		
		void dequeue() {
			if (!front) {
				cout<<"Queue is empty\n";
			}
			
			Node* temp = front;
			front = front->next;
			
			if (!front)
			rear = nullptr;
			
			delete temp;
			
			cout<<"Dequeued from queue\n";
		}
		
		void peek() const {
			if (!front) {
				cout << "Queue is empty\n";
				return;
			}
			
			cout << "Front element is: "<<front->data<<endl;
		}
};

int main() {
	Queue queue;
	
	queue.enqueue(10);
	queue.enqueue(20);
	queue.peek();
	queue.dequeue();
	queue.peek();
	
	return(0);
}