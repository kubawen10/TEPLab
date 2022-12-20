#ifndef TREE_DYNAMIC_H
#define TREE_DYNAMIC_H

#include <iostream>
#include <vector>

template<typename T> class TreeDynamic;

template<typename T> class NodeDynamic {
public:
	NodeDynamic() {
		value = T();
		parentNode = NULL;
	}

	NodeDynamic(T value) {
		this->value = value;
		parentNode = NULL;
	}

	~NodeDynamic() {
		for (int i = 0; i < children.size(); i++) {
			delete children[i];
		}
	}

	void setValue(T newVal) {
		value = newVal;
	}

	int getChildrenNumber() {
		return(children.size());
	}

	void addNewChild() {
		NodeDynamic<T>* newNode = new NodeDynamic<T>();
		newNode->parentNode = this;
		children.push_back(newNode);
	}

	void addNewChild(T value) {
		NodeDynamic<T>* newNode = new NodeDynamic<T>(value);
		newNode->parentNode = this;
		children.push_back(newNode);
	}

	NodeDynamic<T>* getChild(int childOffset) {
		if (childOffset < 0 || childOffset >= children.size()) {
			std::cerr << "Index out of bounds";
			return NULL;
		}

		return children[childOffset];
	}

	void print() {
		std::cout << "Value: " << value << '\n';
	}

	void printAllBelow() {
		if (children.size() == 0) {
			std::cout << "No children for node with value: " << value << '\n';
			return;
		}

		std::cout << "Children for node with value: " << value << '\n';
		for (int i = 0; i < children.size(); i++) {
			children[i]->print();
			children[i]->printAllBelow();
		}
		std::cout << '\n';
	}

	void printUp() {
		print();
		if (parentNode != NULL) parentNode->printUp();
	}

private:
	friend TreeDynamic<T>;

	std::vector<NodeDynamic<T>*> children;
	NodeDynamic<T>* parentNode;
	T value;

	void addNewChild(NodeDynamic<T>* newChild) {
		//std::cout << "Adding new child copy: \n";
		newChild->parentNode = this;
		children.push_back(newChild);
	}

	bool removeChildFromVector(NodeDynamic<T>* childToRemove)
	{
		for (int i = 0; i < children.size(); i++) {
			if (children[i] == childToRemove) {
				children.erase(children.begin() + i);
				return true;
			}
		}

		return false;
	}
};

template<typename T> class TreeDynamic
{
public:
	TreeDynamic() {
		root = new NodeDynamic<T>();
	}

	~TreeDynamic() {
		delete root;
	}

	NodeDynamic<T>* getRoot() {
		return(root);
	}

	void printTree() {
		root->print();
		root->printAllBelow();
	}

	bool moveSubtree(NodeDynamic<T>* parentNode, NodeDynamic<T>* newChildNode) {
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

private:
	NodeDynamic<T>* root;
};

#endif