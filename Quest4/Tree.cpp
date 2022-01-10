//Student ID: 20447032
//Quest4: krazy the koala

#include <iostream>
#include "Tree.h"
#include <vector>
#include <string>

using namespace std;

Tree::Node*
Tree::Node::insert_sibling(Node *p){
	Node *temp = this;
	while(temp->_sibling != nullptr){
		temp = temp->_sibling;
	}
	temp->_sibling = p;
	return p;
}

Tree::Node*
Tree::Node::insert_child(Node *p){
	if(this->_child == nullptr){
		this->_child = p;
	}
	else {
		this->_child->insert_sibling(p);
	}
	return p;
}

const Tree::Node&
Tree::Node::operator=(const Tree::Node& that){
	if(this != &that){
		if(this->_child != nullptr){
			delete _child;
		}
		this->_child = nullptr;
		if(this->_sibling != nullptr){
			delete this->_sibling;
		}
		this->_sibling = nullptr;
		this->_data = that._data;
		if(that._child != nullptr){
			this->_child = new Node();
			*this->_child = *that._child;
		}
		if(that._sibling != nullptr){
			this->_sibling = new Node();
			*this->_sibling = *that._sibling;
		}
	}
	return *this;
}

Tree::Node::Node(const Node& that){
	*this = that;
}

bool
Tree::Node::is_equal(const Node *p1, const Node *p2){
	if((p1 == nullptr && p2 != nullptr) || 
		(p1 != nullptr && p2 == nullptr)){
		return false;
	}
	if(p1 == nullptr && p2 == nullptr){
		return true;
	}
	if(p1->_data.compare(p2->_data) != 0){
		return false;
	}
	if(!is_equal(p1->_sibling, p2->_sibling)){
		return false;
	}
	if(!is_equal(p1->_child, p2->_child)){
		return false;
	}
	return true;
}

bool
Tree::Node::operator==(const Node& that) const{
	return is_equal(this, &that);
}

bool 
Tree::Node::operator!=(const Node& that) const{
	return !(is_equal(this, &that));

}

string
Tree::Node::to_string() const{
	string result = "";
	result += this->_data + " :";
	Node *n = this->_child;
	while(n != nullptr){
		result += " " + n->_data;
		n = n->_sibling;
	}
	result += "\n";
	if(this->_child != nullptr){
		result += "# Child of " + _data + "\n";
		result += this->_child->to_string();
	}
	if(this->_sibling != nullptr){
		result += "# Next sib of " + _data + "\n";
		result += this->_sibling->to_string();
	}
	return result;
}

Tree::Node::~Node(){
	if(_sibling != nullptr){
		delete _sibling;
		_sibling = nullptr;
	}
	if(_child != nullptr){
		delete _child;
		_child = nullptr;
	}
}

Tree::Tree(){
	_root = new Node ("ROOT");
}

Tree::~Tree(){
	delete _root;
	_root = nullptr;
}

//Deep copy
Tree&
Tree::operator=(const Tree& that){
	if(this != &that){
		if(this->_root != nullptr){
			delete _root;
			this->_root = nullptr;
		}
		this->_root = new Node(that._root->_data);
		*this->_root = *that._root;
	}
	return *this;
}

bool
Tree::operator==(const Tree& that) const {
	return Node::is_equal(this->_root, that._root);
}

bool
Tree::operator!=(const Tree& that) const {
	return !(Node::is_equal(this->_root, that._root));
}

string
Tree::to_string() const {
	string result = "# Tree rooted at " + _root->_data + "\n";
	result += "# The following lines are of the form:\n";
	result += "#   node: child1 child2...\n";
	result += _root->to_string();
	result += "# End of Tree\n";
	return result;
}

void
Tree::make_special_config_1(const vector<string>&name){
	vector<Node*> n;
	for (size_t i = 0; i < name.size(); i++){
		Node *p = new Node(name[i]);
		n.push_back(p);
	}
	
	_root->insert_sibling(n[0]);
	n[0]->insert_sibling(n[1]);
	n[0]->insert_sibling(n[2]);
	n[0]->insert_sibling(n[3]);

	n[0]->insert_child(n[4]);
	n[4]->insert_sibling(n[5]);
	n[1]->insert_child(n[6]);
	n[6]->insert_sibling(n[7]);
	n[2]->insert_child(n[8]);
	n[8]->insert_sibling(n[9]);
	n[3]->insert_child(n[10]);
	n[10]->insert_sibling(n[11]);

	n[4]->insert_child(n[12]);
	n[5]->insert_child(n[13]);
	n[6]->insert_child(n[14]);
	n[7]->insert_child(n[15]);
	n[8]->insert_child(n[16]);
	n[9]->insert_child(n[17]);
	n[10]->insert_child(n[18]);
	n[11]->insert_child(n[19]);
}
