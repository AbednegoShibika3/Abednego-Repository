#include <iostream>

struct Node {
	int key;
	Node* left;
	Node* right;
	
	Node(int value) : key(value), left(nullptr), right(nullptr) {
	}
};

class BinarySearchTree {
	private:
		Node* root;
		
		void insert(Node*& node, int key) {
			if (node == nullptr) {
				node = new Node(key);
			} else if (key < node->key) {
				insert (node->left, key);
			} else {
				insert(node->right, key);
			}
		}
		
		void inorder(Node* node) {
			if (node != nullptr) {
				inorder(node->left);
				std::cout << node->key << " ";
				inorder(node->right);
			}
		}
		
		public:
			BinarySearchTree() : root(nullptr) {}
			
			void insert(int key) {
				insert(root, key);
			}
			
			void inorder() {
				inorder(root);
				std::cout << std::endl;
			}
			};
			
	int main() {
		BinarySearchTree bst;
		bst.insert(5);
		bst.insert(3);
		bst.insert(7);
		bst.insert(2);
		bst.insert(4);
		
		std::cout << "Inorder traversal: ";
		bst.inorder();
		
		return 0;
	}