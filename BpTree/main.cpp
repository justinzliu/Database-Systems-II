#include "Node.h"
#include <iostream>
#include "BpTree.h"
#include <vector>
#include <memory>
#include <string>

using namespace node;
using namespace tree;
using namespace std;

class Pair {
	public:
		int key;
		string data;
		Pair(int k, string d) : key(k), data(d) {}
};
void print_vector(vector<Pair>& l) {
	std::string node_keys = "[";
	for(auto& i : l) {
		node_keys.append(to_string(i.key));
		node_keys.append(",");
	}
	node_keys.pop_back();
	node_keys.append("]");
	cout << node_keys << endl;
}

/////////////////////////////////////////////////////////////////////
//compile with: g++ main.cpp BpTree.cpp Node.cpp -o test -std=c++17//
/////////////////////////////////////////////////////////////////////

int main() {

	vector<Pair> test_list = {Pair{2,"a"}, Pair{11,"b"}, Pair{11,"b"}, Pair{21,"c"}, Pair{8,"d"}, Pair{64,"e"}, Pair{5,"f"}, Pair{23,"g"}, Pair{97,"h"}, Pair{6,"i"}, Pair{19,"j"}, Pair{9,"e"}, Pair{7,"k"}, Pair{8,"l"}};
	BpTree tree{3};
	for(auto& it:test_list) {
		if(!tree.insert(it.key, it.data)) {
			cout << "duplicate detected\n";
		}
	}
	if(tree.remove(97)) {cout << "successful remove\n";}
	tree.printKeys();
	cout << endl;
	tree.printValues();
	cout << tree.find(97) << endl;
	/*
	for(int i=0; i<9; i++) {
		cout << "inserting: " << test_list[i].key << endl;
		tree.insert(test_list[i].key,test_list[i].data);
		tree.printKeys();
		cout << "\n";
	}
	*/

}