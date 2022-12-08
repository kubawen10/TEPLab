#include "TreeStatic.h"

NodeStatic::NodeStatic() {
	std::cout << "Initializing new node\n";
	value = 0;
	parentNode = NULL;
}

NodeStatic::NodeStatic(int value) {
	std::cout << "Initializing new node with value: " << value << "\n";
	this->value = value;
	parentNode = NULL;
}

NodeStatic::NodeStatic(const NodeStatic& copyNode) {
	std::cout << "Copy of " << copyNode.value << "\n";
	value = copyNode.value;
	parentNode = copyNode.parentNode;
	children = copyNode.children;

	for (int i = 0; i < children.size(); i++) {
		children[i].parentNode = this;
	}
}

NodeStatic::~NodeStatic() {
	std::cout << "Deleting Node with value: " << value << "\n";
}

void NodeStatic::addNewChild() {
	std::cout << "Adding new child: \n";
	NodeStatic newNode;
	newNode.parentNode = this;
	children.push_back(newNode);
}

void NodeStatic::addNewChild(int value) {
	std::cout << "Adding new child with value: \n";
	NodeStatic newNode(value);
	newNode.parentNode = this;
	children.push_back(newNode);
}

void NodeStatic::addNewChild(NodeStatic* newChild) {
	std::cout << "Adding new child copy: \n";
	NodeStatic newNode(*newChild);
	newNode.parentNode = this;
	children.push_back(newNode);
}

bool NodeStatic::removeChild(NodeStatic* childToRemove) {
	for (int i = 0; i < children.size(); i++) {
		if (&(children[i]) == childToRemove) {
			children.erase(children.begin() + i);
			return true;
		}
	}

	return false;
}

NodeStatic* NodeStatic::getChild(int childOffset) {
	if (childOffset < 0 || childOffset >= children.size()) {
		std::cerr << "Index out of bounds";
		return NULL;
	}

	return &(children[childOffset]);
}

void NodeStatic::printAllBelow() {
	if (children.size() == 0) {
		std::cout << "No children for node with value " << value << "\n";
		return;
	}

	std::cout << "Children for node with value " << value << "\n";
	for (int i = 0; i < children.size(); i++) {
		children[i].print();
		children[i].printAllBelow();
	}
	std::cout << "\n";
}

void NodeStatic::printUp() {
	print();
	if (parentNode != NULL) parentNode->printUp();
}


//TREE IMPLEMENTATION
TreeStatic::TreeStatic() {

}

TreeStatic::~TreeStatic() {

}

void TreeStatic::printTree() {
	root.print();
	root.printAllBelow();
}

bool TreeStatic::moveSubtree(NodeStatic* parentNode, NodeStatic* newChildNode) {
	if (parentNode == NULL || newChildNode == NULL) {
		std::cerr << "Null pointers\n";
		return false;
	}

	if (newChildNode->getParent() == NULL) {
		std::cerr << "Cant move root\n";
		return false;
	}

	parentNode->addNewChild(newChildNode);
	newChildNode->getParent()->removeChild(newChildNode);
	return true;
}



bool NodeStatic::subnodesHaveGoodParentPointer() const {

	for (int i = 0; i < children.size(); i++) {
		if (children[i].parentNode != this) {
			return false;
		}
	}

	bool haveGoodParent = true;
	for (int i = 0; i < children.size(); i++) {
		haveGoodParent = children[i].subnodesHaveGoodParentPointer();
		if (!haveGoodParent) return false;
	}

	return true;
}
bool TreeStatic::isConsistent() const {
	return root.subnodesHaveGoodParentPointer();
}

void NodeStatic::setParentToNull() {
	parentNode = NULL;
}