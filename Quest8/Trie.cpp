//Student ID: 20447032
//Quest8: photon - the king of tardigrades

#include "Trie.h"

using namespace std;

Trie::Trie(){
	_root = new Trie::Node; 
}

void
Trie::Node::insert(string s){
	Trie::Node *curr = this;
	for(const char *str = s.c_str(); *str; str++) {
		char ch = *str;
		if((size_t) ch >= curr->next.size()){
			curr->next.resize(ch+1);
		}
		if(curr->next[ch] != nullptr){
			curr = curr->next[ch];
		} else {
			curr = curr->next[ch] = new Trie::Node;
		}
	}
	if(curr->next.size() == 0){
		curr->next.resize(1);
	}
	if(curr->next[0] == nullptr){
		curr->next[0] = new Trie::Node;
	}
}

const Trie::Node *Trie::Node::traverse(string s) const{
	const Trie::Node *curr = this;
	for(const char *str = s.c_str(); *str; str++) {
		char ch = *str;
		if(curr->next.size() > (size_t) ch && 
			curr->next[ch] != nullptr){
			curr = curr->next[ch];
		} else {
			return nullptr;
		}
	}
	return curr;
}

bool
Trie::Node::lookup(string s) const{
	cout << s << endl;
	const Trie::Node *n = traverse(s);
	if(n == nullptr){
		return false;
	}
	if(n->next[0] == nullptr){
		return false;
	}
	return true;
}

Trie::~Trie(){
	delete _root;
}

Trie::Node::~Node(){
	Trie::Node *node = this;
	for(size_t i = 0; i < node->next.size(); i++){
		Trie::Node *n = node->next[i];
		if(n != nullptr){
			delete n;
			node->next[i] = nullptr;
		}
	}
	node->next.clear();
}

size_t Trie::Node::get_completions(vector<string> &completions, size_t limit) const {
	struct Continuation {
		const Trie::Node *node;
		string partial;
		Continuation(const Node *p, string s) : node(p), partial(s) {}
	};

	queue<Continuation> unprocessed_nodes;
	completions.clear();
 	for(size_t i = 1; i < this->next.size(); i++) {
		if (this->next[i] != nullptr) {
			string s = string(1,(char) i);
			Continuation c(this->next[i], s);
			unprocessed_nodes.push(c);
		}
	}
	while(!unprocessed_nodes.empty()) {
		Continuation cont = unprocessed_nodes.front();
		unprocessed_nodes.pop();
		if(cont.node->next[0] != nullptr && completions.size() < limit){
			completions.push_back(cont.partial);
		}
		for(size_t i = 1; i < cont.node->next.size(); i++) {
			if (cont.node->next[i] != nullptr) {
				string s = cont.partial + string(1, (char)i);
				Continuation c(cont.node->next[i], s);
				unprocessed_nodes.push(c);
			}
		}
	}
	return completions.size();
}

size_t
Trie::get_completions(string s, vector<string> & completions, size_t limit) const{
	//if(s.empty()){
	//	return _root->get_completions(completions, limit);
	//}
	const Trie::Node *n = _root->traverse(s);
	if(n == nullptr){
		completions.clear();
		return 0;
	}
	return n->get_completions(completions, limit);
}

string
Trie::to_string(size_t limit) const {
	string result = "# Trie contents";
	vector<string> completions;
	this->get_completions("", completions, limit);
	for(size_t i = 0; i < completions.size(); i++){
		result += "\n" + completions[i];
		if(i+1 == limit){
			result += "\n...";
			break;			
		}
	}
	return result + "\n";
}

size_t
Trie::trie_sort(vector<string>& vec) const {
	vec.clear();
	get_completions("", vec, SIZE_MAX);
	return vec.size();
}
