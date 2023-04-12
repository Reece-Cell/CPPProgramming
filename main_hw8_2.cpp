/*
 * INSTRUCTION:
 *     This is a C++ starting code for hw8_2.
 *     When you finish the development, download this file.
 *     Note that the current filename is "main.cpp".
 *     But rename it to "main_hw8_2.cpp".
 *     After that, upload the renamed file on Canvas.
 */

// Finish the head comment with Abstract, ID, Name, and Date.
/*
 * Title: main_hw8_2.cpp
 * Abstract: More dynamic interactions with binary search trees
 * ID: 9190
 * Name: Reece Whitelaw
 * Date: 04/07/2023
 */
#include <iostream>
#include <queue>
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
	void append(int item);
	void inOrder() const;
	void firstNode() const;
	void preOrder() const;
	void postOrder() const;
	int countOneChildNodes() const;
	int countLeaves() const;
	int height() const;
	int getRoot() const;
	void levelOrder() const;
	bool isBST() const;

private:
	void insert(Node *newNode, Node *subTree);
	void append(Node *newNode, Node *subTree);
	void inOrder(Node *subTree) const;
	void firstNode(Node *subTree) const;
	void preOrder(Node *subTree, bool first) const;
	void postOrder(Node *subTree, bool first) const;
	int countOneChildNodes(Node *subTree) const;
	int countLeaves(Node *subTree) const;
	int height(Node *subTree) const;
	void levelOrder(Node *subtree) const;
	bool isBST(Node *subTree) const;
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

void BST::append(Node *newNode, Node *subTree) {
	queue<Node *> q;
	q.push(subTree);
	while (!q.empty()) {
		Node *front = q.front();
		q.pop();
		if (front->left == nullptr) {
			front->left = newNode;
			return;
		} else {
			q.push(front->left);
		}
		if (front->right == nullptr) {
			front->right = newNode;
			return;
		} else {
			q.push(front->right);
		}
	}
}
void BST::append(int item) {
	Node *newNode = new Node(item, nullptr, nullptr);
	if (root == nullptr) {
		root = newNode;
	} else {
		append(newNode, root);
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

bool firstNodeprint = true;
void BST::firstNode(Node *subTree) const {
	if (subTree != nullptr) {
		firstNode(subTree->left);
		if (firstNodeprint == true) {
			cout << subTree->data;
			firstNodeprint = false;
		}
	}
}
bool printInOrder = true;
void BST::inOrder(Node *subTree) const {
	if (subTree != nullptr) {
		inOrder(subTree->left);
		if (printInOrder == true) {
			cout << subTree->data;
            printInOrder = false;
		} else {
			cout  << " " << subTree->data;
		}
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

bool printLevel = true;
void BST::levelOrder(Node *subTree) const {
	// Following pseudcode provided by Dr Byun
	/*
	// You can use a queue with functions such as q.push(), q.front(), q.pop(),
	q.empty(), etc.
	// Note that you also need additional code to check for error cases such as
	null pointer. queue<Node*> q; // Queue to keep the Node references (or
	pointers). q.push(root);   // Start from the root node. while (!q.empty()) {
	// Get the first Node (= front Node) in the queue and remove it from the
	queue.
	// Display the data of the Node.
	// Check if the Node has the left child Node and add it to the queue if it
	exists.
	// Check if the Node has the right child Node and add it to the queue if it
	exists.
	}*/
	if (subTree == nullptr) {
		return;
	}
	queue<Node *> q;
	q.push(subTree);
	while (!q.empty()) {
		Node *front = q.front();
		q.pop();
		if (printLevel == false) {
			cout << " " << front->data;
		} else {
			cout << front->data;
			printLevel = false;
		}
		if (front->left != nullptr) {
			q.push(front->left);
		}
		if (front->right != nullptr) {
			q.push(front->right);
		}
	}
}

bool BST::isBST(Node *subTree) const {
	if (subTree == nullptr) {
		return true;
	}
	if (subTree->left != nullptr && subTree->left->data > subTree->data) {
		return false;
	}
	if (subTree->right != nullptr && subTree->right->data < subTree->data) {
		return false;
	}
	return isBST(subTree->left) && isBST(subTree->right);
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

int BST::getRoot() const {
	return root->data;
}

void BST::firstNode() const {
	firstNode(root);
}

void BST::levelOrder() const {
	levelOrder(root);
}
bool BST::isBST() const {
	return isBST(root);
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
	int root;
	cin >> root;
	t1.add(root);
	int inputs;
	cin >> inputs;
	for (int i = 0; i < inputs; i++) {
		string command;
		cin >> command;
		if (command == "add" || command == "append") {
			int adds;
			cin >> adds;
			t1.append(adds);
		} else {
			if (command == "countLeaves") {
				cout << t1.countLeaves();
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
			if (command == "levelOrder") {
				t1.levelOrder();
				printLevel = true;
			}
			if (command == "isBST") {
				if (t1.isBST()) {
					cout << "true";
				} else {
					cout << "false";
				}
			}
			if (command == "findFirstNode") {
				t1.firstNode();
				firstNodeprint = true;
			}
			if (command == "inOrder") {
				t1.inOrder();
                printInOrder = true;
			}
			if (command == "preOrder") {
				t1.preOrder();
			}
			cout << "\n";
		}
	}
	cout << endl;
	return 0;
}
