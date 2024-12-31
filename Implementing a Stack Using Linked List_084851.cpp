#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class Stack {
	private:
		Node* top;
		
	public:
		Stack() : top(nullptr) {}
		
		void push(int x) {
			Node* newNode = new Node();
			newNode->data = x;
			newNode->next = top;
			top = newNode;
			cout <<x<<"Pushed to stack\n";
	}
			
		void pop() {
			if (!top) {
				cout<<"Stack is empty\n";
				return;
			}
			
			Node* temp = top;
			top = top->next;
			delete temp;
			
			cout<<"Popped from stack\n";
		}
		
		void peek() const {
			if (!top) {
				cout << "Stack is empty\n";
				return;
			}
			
			cout << "Top element is: "<<top->data<<endl;
		}
};

int main() {
	Stack stack;
	
	stack.push(10);
	stack.push(20);
	stack.peek();
	stack.pop();
	stack.peek();
	
	return(0);
}