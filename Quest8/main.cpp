#include "Trie.h"

using namespace std;

int main() {
	Trie tree;
	tree.insert("hi");
	tree.insert("hia");
	tree.insert("hib");
	tree.insert("hiac");
	tree.insert("hicd");
	cout << tree.lookup("hi") << endl;
	cout << tree.lookup("hik") << endl;
	cout << tree.lookup("hia") << endl;
	cout << tree.lookup("hicdjshlgfj") << endl;
	vector<string> completions;
	tree.get_completions("hi", completions, 3);
	tree.trie_sort(completions);
	for(auto s = completions.begin(); s != completions.end(); s++){
		cout << *s << endl;
	}
	string result = tree.to_string(3);
	cout << result << endl;
	return 0;
}
