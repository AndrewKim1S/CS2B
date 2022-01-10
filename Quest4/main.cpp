#include "Tree.h"
#include <vector>

using namespace std;

class Tests {
public:

void remove_sibling_of_sibling_root(Tree &t) {
		Tree::Node *n = t._root->_sibling->_sibling;
		delete n;
		t._root->_sibling->_sibling = nullptr;
	}
};


int 
main(){
		vector<string> names = {"AABA", "ABAB", "ABBA", "BABA", "COBO", 
				"COCO", "CODO", "COFO", "COGO", "COHO", "COJO","COKO", "DIBI", "DIDI", 
				"DIFI", "DIGI", "DIHI", "DIJI", "DIKI", "DILI" };

		Tree t1;
		t1.make_special_config_1(names);
		cout << "\n++++ t1 +++++\n" << t1 << endl;

		Tree t2;
		cout << "\n++++ t2 : empty +++++\n" << t2 << endl;
		cout << "t1 and t2 are the same = " << to_string(t1 == t2) << endl;


		t2 = t1;
		cout << "\n++++ t2 : the same with t1 +++++\n" << t2 << endl;
		cout << "t2 is deep copy of t1. They are the same = " << to_string(t1 == t2) << endl;

		Tree t3 = Tree(t1);
		cout << "t3 is shallow copy of t1. They are the same = " << to_string(t1 == t3) << endl;

		Tests s1;
		s1.remove_sibling_of_sibling_root(t1);
		cout << "t1 sibling of sibling of root deleted. t1 t2 are the same = " << to_string(t1 == t2) << endl;
		cout << "t1 t3 are the same = " << to_string(t1 == t3) << endl;
		cout << "t1 :\n" << t1 << endl;
		cout << "t3 :\n" << t3 << endl;

		return 0;
}

