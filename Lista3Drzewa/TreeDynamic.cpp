#include "TreeDynamic.h"

//NODE IMPLEMENTATION

NodeDynamic::NodeDynamic() {
	std::cout << "Initializing new node\n";
	value = 0;
	parentNode = NULL;
}

NodeDynamic::NodeDynamic(int value) {
	std::cout << "Initializing new node with value\n";
	this->value = value;
	parentNode = NULL;
}

NodeDynamic::~NodeDynamic() {
	std::cout << "Deleting Node with value: " << value << "\n";
	for (int i = 0; i < children.size(); i++) {
		delete children[i];
	}
}


void NodeDynamic::addNewChild() {
	std::cout << "Adding new child: \n";
	NodeDynamic* newNode = new NodeDynamic();
	newNode->parentNode = this;
	children.push_back(newNode);
}

void NodeDynamic::addNewChild(int value) {
	std::cout << "Adding new child with value: \n";
	NodeDynamic* newNode = new NodeDynamic(value);
	newNode->parentNode = this;
	children.push_back(newNode);
}

void NodeDynamic::addNewChild(NodeDynamic* newChild) {
	std::cout << "Adding new child copy: \n";
	newChild->parentNode = this;
	children.push_back(newChild);
}

NodeDynamic* NodeDynamic::getChild(int childOffset) {
	if (childOffset < 0 || childOffset >= children.size()) {
		std::cerr << "Index out of bounds";
		return NULL;
	}

	return children[childOffset];
}

bool NodeDynamic::removeChildFromVector(NodeDynamic* childToRemove)
{//dont delete it, its used in move function
	for (int i = 0; i < children.size(); i++) {
		if (children[i] == childToRemove) {
			children.erase(children.begin() + i);
			return true;
		}
	}

	return false;
}

void NodeDynamic::printAllBelow() {
	if (children.size() == 0) {
		std::cout << "No children for node with value " << value << "\n";
		return;
	}

	std::cout << "Children for node with value " << value << "\n";
	for (int i = 0; i < children.size(); i++) {
		children[i]->print();
		children[i]->printAllBelow();
	}
	std::cout << "\n";
}

void NodeDynamic::printUp() {
	print();
	if (parentNode != NULL) parentNode->printUp();
}


//TREE IMPLEMENTATION
TreeDynamic::TreeDynamic() {
	root = new NodeDynamic();
}

TreeDynamic::~TreeDynamic() {
	delete root;
}

void TreeDynamic::printTree() {
	root->print();
	root->printAllBelow();
}

bool TreeDynamic::moveSubtree(NodeDynamic* parentNode, NodeDynamic* newChildNode) {
	if (parentNode == NULL || newChildNode == NULL) {
		std::cerr << "Null pointers\n";
		return false;
	}

	if (newChildNode->parentNode == NULL) {
		std::cerr << "Cant move root\n";
		return false;
	}

	newChildNode->parentNode->removeChildFromVector(newChildNode);
	parentNode->addNewChild(newChildNode);
	return true;
}
