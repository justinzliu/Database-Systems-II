#include "BpTree.h"
#include "Node.h"

using namespace node;
using namespace tree;
using namespace std;

//constructors
BpTree::BpTree(int num_keys) : max_keys(num_keys), height(0), root(std::shared_ptr<node::Node>()) {
	root = std::make_shared<node::Node>(num_keys);
}

Node* BpTree::getNode(const int key) {
	//locate leaf node containing key
	int curr_height = 1;
	Node* curr_node = &(*root);
	std::vector<int>* curr_keys = root->getKeys();
	while(curr_height < height) {
		int child_index = 0;
		std::vector<int>::iterator i;
		for(i = curr_keys->begin(); i!=curr_keys->end(); i++) {
			if(key < *i) {
				//traverse left
				curr_height++;
				curr_node = curr_node->getDecendant(child_index);
				break;
			}
		}
		if(i == curr_keys->end()) {
			//end of keys reached, traverse right most
			curr_height++;
			curr_node = curr_node->getDecendant(child_index+1);
		}
	}
	return curr_node;
}  

bool BpTree::insert(int key, std::string data) {
	if(height == 0) {
		//empty tree
		root->insertKey(key,data);
		height++;
	}
	else {
		Node* node = getNode(key);
		node->insertKey(key,data);
	}
	/*
	Key new_key{key,data};
	if (height == 0) {
		//tree has no root
		root.addKey(new_key);
		height++;
	}
	else {
		//root exists
		int curr_height = 1;
		Node* curr_node = &root;
		//locate node to insert into
		while (curr_height < height) {
			curr_height++;
		}
		(*curr_node).insert(new_key);
	}
	*/
	return true;
}

void BpTree::printKeys() {
	root->printKeys_byLvl();
}
