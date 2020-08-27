#include "Node.h"
#ifndef BPTREE_H
#define BPTREE_H

namespace tree {

class BpTree {
	private:
		int max_keys;
		int height;
		node::Node* root;
		//helper functions
		node::Node* getNode(const int key);
	public:
		//constructors & destructors & copier
		explicit BpTree(int num_keys);
		~BpTree();
		 BpTree(const BpTree &tree) {max_keys=tree.max_keys; height=tree.height; root=tree.root;}
		//functions
		int getHeight() {return height;}
		bool insert(int key, std::string data);
		std::string find(const int key);
		void printKeys();
		void printValues();
		bool remove(int key);
};

}

#endif