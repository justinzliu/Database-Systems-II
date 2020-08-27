#include "Node.h"
#include <assert.h>

using namespace node;
using namespace std;

////////////////
//constructors//
////////////////
/* UNIQUE PTR
Node::Node() : max_size(1), keys(vector<int>()), children(vector<unique_ptr<Node>>()), data(vector<unique_ptr<string>>()), parent(NULL) {}

Node::Node(int size): max_size(size), keys(vector<int>()), children(vector<unique_ptr<Node>>()), data(vector<unique_ptr<string>>()), parent(NULL) {}

Node::Node(int size, int key, string str) : max_size(size), keys(vector<int>()), children(vector<unique_ptr<Node>>()), data(vector<unique_ptr<string>>()), parent(NULL) {
	if (!insertKey(key,str)) {
		cout << "insert failed.";
	}
}

Node::Node(int& size, vector<int>& key_list, vector<unique_ptr<string>>& data_vec) : max_size(size), keys(key_list), children(vector<unique_ptr<Node>>()), data(std::move(data_vec)), parent(NULL) {}
*/
Node::Node() : max_size(1), keys(vector<int>()), children(vector<shared_ptr<Node>>()), data(vector<unique_ptr<string>>()), parent(NULL) {}

Node::Node(int size): max_size(size), keys(vector<int>()), children(vector<shared_ptr<Node>>()), data(vector<unique_ptr<string>>()), parent(NULL) {}

Node::Node(int size, int key, string str) : max_size(size), keys(vector<int>()), children(vector<shared_ptr<Node>>()), data(vector<unique_ptr<string>>()), parent(NULL) {
	if (!insertKey(key,str)) {
		cout << "insert failed.";
	}
}

Node::Node(int& size, vector<int>& key_list, vector<shared_ptr<Node>>& children_vec, vector<unique_ptr<string>>& data_vec, Node* par) : max_size(size), keys(key_list), children(children_vec), data(std::move(data_vec)), parent(par) {}

////////////////////
//helper functions//
////////////////////

/*
bool Node::insertChild(shared_ptr<Node> node) {
	int key = node->keys[0];
}
*/

void Node::printKeys_Node(const Node& node) {
	//print current node
	std::string node_keys = "[";
	//int fillCount = max_size;
	for(auto& key:keys) {
		node_keys.append(to_string(key));
		node_keys.append(",");
		//max_size--;
	}
	node_keys.pop_back();
	node_keys.append("]");
	cout << node_keys << " ";
}

shared_ptr<Node> Node::splitNode() {

	//DEBUGGING
	int keys_size = keys.size();
	//currentNode will be the leftNode
	int key_middleIndex = ceil((max_size+1)/2); //currNode.keys = indices[0,middleIndex] and rightNode.keys = indices(middleIndex,endIndex]
	int child_middleIndex = ceil((max_size+2)/2); //currNode.children = indices[0,middleIndex] and rightNode.children = indices(middleIndex,endIndex]

	vector<int> rightNode_keys;
	std::vector<std::shared_ptr<Node>> rightNode_children;
	std::vector<std::unique_ptr<std::string>> rightNode_data;
	//move (key_middleIndex,endIndex] keys and data to rightNode

	//l2.insert(l2.begin()+1,make_move_iterator(l1.begin()),make_move_iterator(l1.end()));
	//set rightNode keys and remove keys from leftNode
	vector<int>::iterator it_rightNode_start = keys.begin()+key_middleIndex;
	rightNode_keys.insert(rightNode_keys.begin(), it_rightNode_start, keys.end());
	keys.erase(it_rightNode_start, keys.end());
	//set rightNode data and remove data from leftNode
	
	//set rightNode children and remove children from leftNode
	
	//DEBUGGING
	auto rightNode = std::make_shared<Node>(max_size, rightNode_keys, rightNode_children, rightNode_data, parent);
	this->children.push_back(rightNode); //leftNode.children[max_size] points to rightNode
	assert(rightNode.use_count() == 2);
	return move(rightNode);
}

////////////////////
//member functions//
////////////////////

bool Node::insertKey(const int& key, const string& str) {
	//cout << "in node.insertKey" << endl;
	//leftNode is "this"
	if (this->isFull()) {
	
		//cout << "in node.insertKey if statement" << endl;
		//full node, will need to split into two nodes
		
		shared_ptr<Node> rightNode = splitNode();
		assert(rightNode.use_count() == 2);
		//make new parent node and complete links for children
		shared_ptr<Node> newParent{max_size};
		newParent->children.push_back(move(this));
		newParent->children.push_back(move(rightNode))
		if (this->isRoot()) {
			//create new root node
			
		}
		//int child_index = 0;
		std::vector<int>::iterator i;
		for(i = parent->keys.begin(); i!=parent->keys.end(); i++) {
			if(key < *i) {
				//traverse left
				curr_height++;
				curr_node = curr_node->getDecendant(child_index);
				break;
			}
			else if(i == curr_keys->end()) {
				//end of keys reached, traverse right most
				curr_height++;
				curr_node = curr_node->getDecendant(child_index+1);
				break;
			}
		}
	
	}
	else {
		//cout << "in node.insertKey else statement" << endl;
		vector<int>::iterator i;
		//room in node for another key, typical insert
		for(i = keys.begin(); i!=keys.end(); i++) {
			if (*i > key) {
				keys.insert(i,key);
				break;
			}
		}
		if (i == keys.end()) {
			//cout << "inserting into empty" << endl;
			keys.push_back(key);
		}
	}
	return true;
}

void Node::printKeys_byLvl() {
	printKeys_Node(*this);
}