/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw8_1.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw8_1.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw8_1.cpp
 * Abstract: Simple binary search tree program.
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 04/07/2023
 */
// A sample BST (Binary Search Tree) program in C++ for CST370.
#include <iostream>
#include <string>
using namespace std;

// A class to define a tree node.
class Node {
public:
	// Constructor
	Node(int newData, Node *newLeft, Node *newRight)
		: data(newData), left(newLeft), right(newRight) {
		// Intentional empty.
	}

public: // Use "public" to make the program simple (= no getters and setters).
	int data;
	Node *left;
	Node *right;
};

bool postprinter = true;
// A class for a BST which may include many Nodes.
class BST {
public:
	BST();
	void add(int item);
	void inOrder() const;
	void preOrder() const;
	void postOrder() const;
	int countOneChildNodes() const;
	int countLeaves() const;
	int height() const;

private:
	void insert(Node *newNode, Node *subTree);
	void inOrder(Node *subTree) const;
	void preOrder(Node *subTree, bool first) const;
	void postOrder(Node *subTree, bool first) const;
	int countOneChildNodes(Node *subTree) const;
	int countLeaves(Node *subTree) const;
	int height(Node *subTree) const;
	Node *root;
};

// Constructor
BST::BST() : root(nullptr) {
	// Intentional empty.
}

// Insert a new node under the subtree using recursion
void BST::insert(Node *newNode, Node *subTree) {
	// Go to left subtree
	if (newNode->data < subTree->data) {
		if (subTree->left == nullptr) {
			subTree->left = newNode;
		} else {
			insert(newNode, subTree->left);
		}
	} else // Go to right subtree
	{
		if (subTree->right == nullptr) {
			subTree->right = newNode;
		} else {
			insert(newNode, subTree->right);
		}
	}
}

// Add an item to the BST.
// Internally, it calls "insert()" for actual insertion if root is not null.
void BST::add(int item) {
	Node *newNode = new Node(item, nullptr, nullptr);
	if (root == nullptr) {
		root = newNode;
	} else {
		insert(newNode, root);
	}
}

void BST::inOrder(Node *subTree) const {
	if (subTree != nullptr) {
		inOrder(subTree->left);
		cout << subTree->data << " ";
		inOrder(subTree->right);
	}
}
int BST::countOneChildNodes(Node *subTree) const {
	int count = 0;
	if (subTree != nullptr) {
		count += countOneChildNodes(subTree->left);
		if ((subTree->left == nullptr && subTree->right != nullptr) ||
			(subTree->left != nullptr && subTree->right == nullptr)) {
			count++;
		}
		count += countOneChildNodes(subTree->right);
	}
	return count;
}
void BST::postOrder(Node *subTree, bool first) const {
	if (subTree != nullptr) {
		postOrder(subTree->left, false);
		postOrder(subTree->right, false);
		if (postprinter == true) {
			cout << subTree->data;
			postprinter = false;
		} else {
			cout << " " << subTree->data;
		}
	}
}
void BST::preOrder(Node *subTree, bool first) const {
	if (subTree != nullptr) {
		if (first == true) {
			cout << subTree->data;
		} else {
			cout << " " << subTree->data;
		}
		preOrder(subTree->left, false);
		preOrder(subTree->right, false);
	}
}
int BST::countLeaves(Node *subTree) const {
	if (subTree == nullptr) {
		return 0;
	}
	if (subTree->left == nullptr && subTree->right == nullptr) {
		return 1;
	}
	return countLeaves(subTree->left) + countLeaves(subTree->right);
}
int BST::height(Node *subTree) const {
	if (subTree == nullptr) {
		return -1;
	}
	int leftH = height(subTree->left);
	int rightH = height(subTree->right);
	if (leftH > rightH) {
		return leftH + 1;
	} else {
		return 1 + rightH;
	}
}

int BST::countOneChildNodes() const {
	return countOneChildNodes(root);
}

void BST::postOrder() const {
	postOrder(root, true);
}

void BST::preOrder() const {
	preOrder(root, true);
}

int BST::height() const {
	return height(root);
}

int BST::countLeaves() const {
	return countLeaves(root);
}
// Conduct the in-order traversal.
// Actual traversal happens in another function named inOrder() with the root.
// We have two inOrder() functions (= function overloading).
void BST::inOrder() const {
	inOrder(root);
}

int main() {
	// Sample BST t1
	//
	//        50
	//       /  \
    //     20   70
	//    /  \    \
    //   10   35   90

	BST t1;
	int inputs;
	cin >> inputs;
	for (int i = 0; i < inputs; i++) {
		string command;
		cin >> command;
		if (command == "add" || command == "append") {
			int adds;
			cin >> adds;
			t1.add(adds);
		} else {
			if (command == "countLeaves") {
				cout << t1.countLeaves();
			}
			if (command == "preOrder") {
				t1.preOrder();
			}
			if (command == "postOrder") {
				t1.postOrder();
				postprinter = true;
			}
			if (command == "countOneChildNodes") {
				cout << t1.countOneChildNodes();
			}
			if (command == "height") {
				cout << t1.height();
			}
			cout << "\n";
		}
	}

	// cout << "===== Inorder Traversal =====\n";
	// t1.inOrder();
	cout << endl;

	return 0;
}