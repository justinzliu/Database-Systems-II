#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

namespace node {

class Node {
    private:
        //members
        int max_size;
        std::vector<int> keys;
        std::vector<Node*> children;
        std::vector<std::string> data;
        Node* parent;
        //helper functions
        Node* splitNode();
        void insertInterior(Node* child);
    public:
        //constructor, destructor, and copier
        Node();
        Node(int size);
        Node(int size, int key, std::string str);
        Node(int& size, std::vector<int>& key_list, std::vector<Node*>& children_vec, std::vector<std::string>& data_vec, Node* par);
        Node(const Node &node) {max_size=node.max_size; keys=node.keys; children=node.children; data=node.data; parent=node.parent;}
        ~Node();
        //functions
        bool insertKey(const int key, const std::string str);
        void newRoot(Node* leftNode,Node* rightNode);
        bool isRoot() {return parent == NULL;}
        bool isLeaf() {return !data.empty();}
        int isFull() {return keys.size() > max_size;}
        std::vector<int>* getKeys() {return &keys;}
        Node* getParent() {return parent;}
        Node* getDecendant(int index) {return children[index];}
        std::vector<Node*> getChildren() {return children;} 
        std::string find_inNode(const int key);
        void printKeys_Node();
        void printData_Node();
        bool removeKey(int key);
};

}

#endif