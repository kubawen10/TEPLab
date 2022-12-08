#ifndef TREE_DYNAMIC_H
#define TREE_DYNAMIC_H

#include <iostream>
#include <vector>

class TreeDynamic;

class NodeDynamic {
public:
	NodeDynamic();
	NodeDynamic(int value);
	~NodeDynamic();

	void setValue(int newVal) {
		value = newVal;
	};

	int getChildrenNumber() {
		return(children.size());
	};

	void addNewChild();
	void addNewChild(int value);

	NodeDynamic* getChild(int childOffset);

	void print() {
		std::cout << "Value: " << value << "\n";
	};
	void printAllBelow();
	void printUp();

private:
	friend TreeDynamic;

	std::vector<NodeDynamic*> children;
	NodeDynamic* parentNode;
	int value;

	void addNewChild(NodeDynamic* newChild);
	bool removeChildFromVector(NodeDynamic* childToRemove);
};


class TreeDynamic
{
public:
	TreeDynamic();
	~TreeDynamic();

	NodeDynamic* getRoot() {
		return(root);
	};

	void printTree();

	bool moveSubtree(NodeDynamic* parentNode, NodeDynamic* newChildNode);

private:
	NodeDynamic* root;
};

#endif