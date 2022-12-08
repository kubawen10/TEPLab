#ifndef TREE_STATIC_H
#define TREE_STATIC_H

#include <vector>
#include <iostream>

class NodeStatic {
public:
	NodeStatic();
	NodeStatic(int value);
	NodeStatic(const NodeStatic& copyNode);
	~NodeStatic();

	void setValue(int newVal) {
		value = newVal;
	};

	int getChildrenNumber() {
		return(children.size());
	};

	void addNewChild();
	void addNewChild(int value);
	void addNewChild(NodeStatic* newChild);

	bool removeChild(NodeStatic* childToRemove);

	NodeStatic* getChild(int childOffset);

	NodeStatic* getParent() {
		return parentNode;
	}
	void setParentToNull();

	void print() {
		std::cout << "Value: " << value << "\n";
	};
	void printParent() {
		if (parentNode == NULL) {
			std::cout << "Parent is: NULL\n";
		}
		else {
			std::cout << "Parent is: ";
			parentNode->print();
		}
	};
	void printAllBelow();
	void printUp();
	bool subnodesHaveGoodParentPointer() const;

private:
	std::vector<NodeStatic> children;
	NodeStatic* parentNode;
	int value;
};

class TreeStatic
{
public:
	TreeStatic();
	~TreeStatic();
	NodeStatic* getRoot() {
		return(&root);
	};
	void printTree();
	bool moveSubtree(NodeStatic* parentNode, NodeStatic* newChildNode);
	bool isConsistent() const;
private:
	NodeStatic root;
};

#endif