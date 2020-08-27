#include "BpTree.h"
#include "Node.h"
#include <queue>

using namespace node;
using namespace tree;
using namespace std;

////////////////////////////////////////
//constructors & destructors & copiers//
///////////////////////////////////////

BpTree::BpTree(int num_keys) {
	max_keys = num_keys;
	height = 0;
	root = new node::Node(num_keys);
}

BpTree::~BpTree() {
	delete root;
}

////////////////////
//helper functions//
////////////////////

Node* BpTree::getNode(const int key) {
	//locate leaf node containing key
	Node* curr_node = root;
	std::vector<int>* curr_keys;
	while(!curr_node->isLeaf()) {
		curr_keys = curr_node->getKeys();
		int child_index = 0;
		std::vector<int>::iterator i;
		for(i = curr_keys->begin(); i!=curr_keys->end(); i++) {
			if(key < *i) {
				//traverse left
				curr_node = curr_node->getDecendant(child_index);
				break;
			}
			child_index ++;
		}
		if(i == curr_keys->end()) {
			curr_node = curr_node->getDecendant(child_index);

		}
	}
	return curr_node;
}  

////////////////////
//member functions//
////////////////////

bool BpTree::insert(int key, std::string data) {
	bool result;
	if(height == 0) {
		//empty tree
		root->insertKey(key,data);
		height++;
	}
	else {
		Node* node = getNode(key); //locate leaf node to insert into
		result = node->insertKey(key,data);
		while (!root->isRoot()) {
			root = root->getParent();
			height++;
		}
	}
	return result;
}

void BpTree::printKeys() {
	queue<Node*> Q;
	Q.push(root);
	while(!Q.empty()) {
		int Qsize = Q.size();
		while(Qsize > 0) {
			Node* currNode = Q.front();
			currNode->printKeys_Node();
			Q.pop();
			vector<Node*> currNode_children = currNode->getChildren();
			vector<Node*>::iterator begin = currNode_children.begin();
			vector<Node*>::iterator end = currNode_children.end();
			for(begin; begin!=end; begin++) {
				Q.push(*begin);
			}
			Qsize--;
		}
		cout << endl;
	}
}

void BpTree::printValues() {
	queue<Node*> Q;
	Q.push(root);
	while(!Q.empty()) {
		int Qsize = Q.size();
		while(Qsize > 0) {
			Node* currNode = Q.front();
			currNode->printData_Node();
			Q.pop();
			vector<Node*> currNode_children = currNode->getChildren();
			vector<Node*>::iterator begin = currNode_children.begin();
			vector<Node*>::iterator end = currNode_children.end();
			for(begin; begin!=end; begin++) {
				Q.push(*begin);
			}
			Qsize--;
		}
		cout << endl;
	}
}

string BpTree::find(const int key) {
	//locate leaf node containing key
	Node* curr_node = root;
	std::vector<int>* curr_keys;
	while(!curr_node->isLeaf()) {
		curr_keys = curr_node->getKeys();
		int child_index = 0;
		std::vector<int>::iterator i;
		for(i = curr_keys->begin(); i!=curr_keys->end(); i++) {
			if(key < *i) {
				//traverse left
				curr_node = curr_node->getDecendant(child_index);
				break;
			}
			child_index ++;	
		}
		if(i == curr_keys->end()) {
			curr_node = curr_node->getDecendant(child_index);

		}
	}
	return curr_node->find_inNode(key);
}

bool BpTree::remove(int key) {
	Node* node = getNode(key); //locate leaf node to insert into
	return node->removeKey(key);
}  
