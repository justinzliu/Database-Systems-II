#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <math.h>

namespace node {

class Node {
    private:
        //members
        int max_size;
        std::vector<int> keys;
        std::vector<std::shared_ptr<Node>> children;
        std::vector<std::unique_ptr<std::string>> data;
        Node* parent;
        //helper functions
        void printKeys_Node(const Node& node);
        std::shared_ptr<Node> splitNode();
        //bool insertChild(const std::string& str);
    public:
        //constructors
        Node();
        Node(int size);
        Node(int size, int key, std::string str);
        //Node(int& size, std::vector<int>& key_list, std::vector<std::unique_ptr<std::string>>& data_vec);
        Node(int& size, std::vector<int>& key_list, std::vector<std::shared_ptr<Node>>& children_vec, std::vector<std::unique_ptr<std::string>>& data_vec, Node* par);
        //functions
        bool insertKey(const int& key, const std::string& str);
        //void addKey(Key& key);
        //gets values and debug
        bool isRoot() {return parent == NULL;}
        bool isLeaf() {return !data.empty();}
        int isFull() {return keys.size() >= max_size;}
        std::vector<int>* getKeys() {return &keys;}
        Node* getParent() {return parent;}
        Node* getDecendant(int index) {return children[index].get();}
        void printKeys_byLvl(); //prints all keys in node and children of node
};

/* removing key class and refactoring node class
class Key;
class Node;

class Key {
    private:
        int val;
        std::string data;
        std::vector<Node> children; //index 0 is left child, index 1 is right child
    public:
        //constructors
        Key(int key_val, std::string key_data);
        explicit Key(int key_val);
        //functions
    	bool isLeaf() {return !data.empty();}
        int getVal() {return val;}
        std::string getData() {return data;}
        std::vector<Node>* getChildren() {return &children;}
};


class Node {
    private:
        int curr_size;
        std::vector<Key> keys;
        Node* parent;
    public:
        //constructors
        Node() : curr_size(0), keys(std::vector<Key>()), parent(NULL) {}
        Node(Key& key, Node* par) : curr_size(1), keys(std::vector<Key>()), parent(par) {}
        explicit Node(std::vector<Key>& keys_list) : curr_size(10), keys(keys_list), parent(NULL) {} //used for debugging, remove later
        //functions
        bool insert(Key& key);
        void addKey(Key& key);
        //gets values and debug
        int getSize() {return curr_size;}
        std::vector<Key>* getKeys() {return &keys;}
        Node* getParent() {return parent;}
        void print_subtree(); //prints all keys in node and children of node
};
*/

}

#endif