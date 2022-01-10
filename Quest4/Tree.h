//Student ID: 20447032
//Quest4: krazy the koala

#ifndef Tree_h
#define Tree_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tree {
private:
	struct Node { // Inner class
		string _data;
		Node *_sibling, *_child;
		static bool is_equal(const Node *p1, const Node *p2);

		Node(string s = "") : _data(s), _sibling(nullptr), _child(nullptr) {}
		Node(const Node& that);
		const Node& operator=(const Node& that); // Deep clone
		~Node();

		string get_data() const { return _data; }
		void set_data(string s) { _data = s; }

		Node *insert_sibling(Node *p);
		Node *insert_child(Node *p);

		string to_string() const;

		bool operator==(const Node& that) const;
		bool operator!=(const Node& that) const;
	};

	Node *_root;

public:
	Tree();
	~Tree();
	
	Tree(const Tree& that) { *this = that; }
	Tree& operator=(const Tree& that); // Deep clone

	string to_string() const;
	void make_special_config_1(const std::vector<std::string>& names);

	bool operator==(const Tree& that) const;
	bool operator!=(const Tree& that) const;

	friend std::ostream& operator<<(std::ostream& os, const Tree& tree){
		os << tree.to_string();
		return os;
	}

	friend class Tests; // Don't remove this line

};

#endif /* Tree_h */
