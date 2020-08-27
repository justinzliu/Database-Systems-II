#include "Node.h"
#ifndef BPTREE_H
#define BPTREE_H

namespace tree {

class BpTree {
	private:
		int max_keys;
		int height;
		std::shared_ptr<node::Node> root;

	public:
		explicit BpTree(int num_keys);
		int getHeight() {return height;}
		bool insert(int key, std::string data);
		void printKeys();
		//WIP
		node::Node* getNode(const int key);

		/*
		bool remove(int key);
		std::string find(int key);
		void printValues();
		*/
};

}

#endif