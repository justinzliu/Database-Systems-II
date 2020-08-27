#include "Node.h"
#include <assert.h>

using namespace node;
using namespace std;

////////////////////////////////////////
//constructors & destructors & copiers//
///////////////////////////////////////

Node::Node() : max_size(1), keys(vector<int>()), children(vector<Node*>()), data(vector<string>()), parent(NULL) {}

Node::Node(int size): max_size(size), keys(vector<int>()), children(vector<Node*>()), data(vector<string>()), parent(NULL) {}

Node::Node(int size, int key, string str) : max_size(size), keys(vector<int>()), children(vector<Node*>()), data(vector<string>()), parent(NULL) {
	if (!insertKey(key,str)) {
		cout << "insert failed.";
	}
}

Node::Node(int& size, vector<int>& key_list, vector<Node*>& children_vec, vector<string>& data_vec, Node* par) : max_size(size), keys(key_list), children(children_vec), data(data_vec), parent(par) {}

Node::~Node() {
    //destroy keys
    keys.clear();
    //destroy children
    for(auto child:children) {delete child;}
    children.clear();
	//delete data;
	data.clear();
}

////////////////////
//helper functions//
////////////////////

Node* Node::splitNode() {

	//DEBUGGING
	int keys_size = keys.size();
	//currentNode will be the leftNode
	int key_middleIndex = ceil((max_size+1)/2); //currNode.keys = indices[0,middleIndex] and rightNode.keys = indices(middleIndex,endIndex]
	int child_middleIndex = ceil((max_size+2)/2); //currNode.children = indices[0,middleIndex] and rightNode.children = indices(middleIndex,endIndex]
	//set rightNode keys and remove keys from leftNode
	vector<int> rightNode_keys;
	vector<int>::iterator it1_rightNode_start = keys.begin()+key_middleIndex;
	rightNode_keys.insert(rightNode_keys.begin(), it1_rightNode_start, keys.end());
	keys.erase(it1_rightNode_start, keys.end());
	//set rightNode children and remove children from leftNode
	//set rightNode data and remove data from leftNode
	std::vector<std::string> rightNode_data;
	std::vector<Node*> rightNode_children;
	if(this->isLeaf()) {
		vector<string>::iterator it3_rightNode_start = data.begin()+key_middleIndex;
		rightNode_data.insert(rightNode_data.begin(), it3_rightNode_start, data.end());
		data.erase(it3_rightNode_start, data.end());
		//set left leaf pointing to right sibling
	}
	else {
		vector<Node*>::iterator it2_rightNode_start = children.begin()+child_middleIndex;
		rightNode_children.insert(rightNode_children.begin(), it2_rightNode_start, children.end());
		children.erase(it2_rightNode_start, children.end());
	}
	Node* rightNode = new Node(max_size, rightNode_keys, rightNode_children, rightNode_data, parent);
	//this->children.push_back(rightNode); //leftNode.children[max_size] points to rightNode
	return rightNode;
}

void Node::insertInterior(Node* child) {
	int key = child->keys[0];
	vector<int>::iterator i;
	int index = 1;
	//insert key and right from previous insert into leaf node
	for(i = keys.begin(); i!=keys.end(); i++) {
		if (*i > key) {
			keys.insert(i,key);
			children.insert(children.begin()+index,child);
			break;
		}
		index++;
	}
	if (i == keys.end()) {
		//key larger than any keys
		keys.push_back(key);
		children.push_back(child);
	}
}

////////////////////
//member functions//
////////////////////

void Node::newRoot(Node* leftNode, Node* rightNode) {
	//create new root node	
	//make new parent node, push rightNode.keys[0] up, and complete links for children
	Node* newParent = new Node{max_size};
	newParent->keys.push_back(rightNode->keys[0]);
	newParent->children.push_back(leftNode);
	newParent->children.push_back(rightNode);
	leftNode->parent = newParent;
	rightNode->parent = newParent;
}

bool Node::insertKey(const int key, const string str) {
	//leftNode is "this"
	vector<int>::iterator i;
	int index = 0;
	//insert key and string into leaf node
	for(i = keys.begin(); i!=keys.end(); i++) {
		if (*i == key) {return false;}
		else if (*i > key) {
			keys.insert(i,key);
			data.insert(data.begin()+index,str);
			break;
		}
		index++;
	}
	if (i == keys.end()) {
		//key larger than any keys
		keys.push_back(key);
		data.push_back(str);
	}
	if (this->isFull()) {
		//full node, will need to split into two nodes
		Node* rightNode = splitNode();
		if (this->isRoot()) {
			newRoot(this,rightNode);
		}
		else {
			this->parent->insertInterior(rightNode);
		}
	}
	return true;
}

void Node::printKeys_Node() {
	//print current node
	std::string node_keys = "[";
	for(auto& key:this->keys) {
		node_keys.append(to_string(key));
		node_keys.append(",");
	}
	node_keys.pop_back();
	node_keys.append("]");
	cout << node_keys << " ";
}

void Node::printData_Node() {
	//print current node
	if (this->isLeaf()) {
		std::string node_keys = "[";
		for(auto& d:this->data) {
			node_keys.append("'");
			node_keys.append(d);
			node_keys.append("'");
			node_keys.append(",");
		}
		node_keys.pop_back();
		node_keys.append("]");
		cout << node_keys << " ";
	}
}

string Node::find_inNode(const int key) {
	int data_index = 0;
	for(auto& i : this->keys) {
		if (i == key) {return this->data[data_index];}
		data_index++;
	}
	return "";
}

bool redistribute() {

}

bool Node::removeKey(int key) {
	int data_index = 0;
	for(auto i = this->keys.begin(); i!=this->keys.end(); i++) {
		if (*i == key) {
			this->keys.erase(i);
			this->data.erase(data.begin()+data_index);

			return true;
		}
		data_index++;
	}
	return false;
}