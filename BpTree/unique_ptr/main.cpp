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
void print_vector(vector<shared_ptr<Pair>>& l) {
	std::string node_keys = "[";
	for(auto& i : l) {
		node_keys.append(to_string(i->key));
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

	vector<Pair> test_list = {Pair{0,"a"}, Pair{1,"b"}, Pair{2,"c"}, Pair{3,"d"}, Pair{4,"e"}, Pair{5,"f"}, Pair{6,"g"}};
	BpTree tree{5};
	tree.insert(test_list[0].key, test_list[0].data);
	tree.insert(test_list[1].key, test_list[1].data);
	tree.insert(test_list[2].key, test_list[2].data);
	tree.insert(test_list[3].key, test_list[3].data);
	tree.insert(test_list[4].key, test_list[4].data);
	tree.insert(test_list[5].key, test_list[5].data);
	tree.printKeys();

/*
	
	// testing normal ptr
	vector<Pair> l1;
	vector<Pair> l2;
	Pair p(0,"a");
	Pair p2(1,"a");
	Pair p3(2,"a");
	Pair p4(3,"a");
	

	//testing unique_ptr
	vector<shared_ptr<Pair>> l1;
	vector<shared_ptr<Pair>> l2;
	shared_ptr<Pair> p = make_shared<Pair>(0,"a");
	shared_ptr<Pair> p2 = make_shared<Pair>(1,"a");
	shared_ptr<Pair> p3 = make_shared<Pair>(2,"a");
	shared_ptr<Pair> p4 = make_shared<Pair>(3,"a");
		
	l1.push_back(std::move(p));
	l1.push_back(std::move(p2));
	l1.push_back(std::move(p3));
	//l2.push_back(std::move(p4));
	l1.insert(l1.begin(),std::move(p4));
	//l1.push_back(std::move(p3));
	move_iterator l2_moveIteratorStart = make_move_iterator(l2.begin());
	move_iterator l2_moveIteratorEnd = make_move_iterator(l2.end());
	l1.insert(l1.begin()+1,l2_moveIteratorStart,l2_moveIteratorEnd);
	//vector<shared_ptr<Pair>>::iterator l1_start = l1.begin();
	//vector<shared_ptr<Pair>>::iterator l1_end = l1.end();
	//l1.erase(l1_start,l1_end);
	print_vector(l1);
	//cout << "size of l2 is: " << l1.size() << endl;
	
	//rightNode_data.insert(0,std::move(data[i]));
*/
	


}