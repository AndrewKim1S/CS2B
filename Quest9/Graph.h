//Student ID: 20447032
//Quest9: just simply bee

#ifndef Graph_h
#define Graph_h

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
protected:
	struct Edge {
		int _dst;
		string _tag;
		Edge(int dst = -1, string tag = "") : _dst(dst), _tag(tag) {}
	};
	vector<vector<Edge>> _nodes;

	void add_edge(int src, int dst, string tag);
	string to_string() const;
	void _nodes_clear(int r);

public:
	void make_silly_snake();
	void make_mr_sticky();
	void make_driftin_dragonfly();
	void make_slinky_star();
	void make_kathy_da_grate();
	void make_dodos_in_space();
	void make_purty_pitcher();

	friend class Tests;
};

#endif /* Graph_h */
