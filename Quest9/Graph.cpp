//Student ID: 20447032
//Quest9: just simply bee

#include "Graph.h"

using namespace std;

void
Graph::_nodes_clear(int r){
	for(size_t i = 0; i < _nodes.size(); i++){
		_nodes[i].clear();
	}
	_nodes.clear();
	_nodes.resize(r);
}

void
Graph::add_edge(int src, int dst, string tag){
	Graph::Edge e(dst, tag);
	_nodes[src].push_back(e);
}

string
Graph::to_string() const {
	string result = "\n_nodes vector is:";
	for(size_t i = 0; i < _nodes.size(); i++){
		for(size_t k = 0; k < _nodes[i].size(); k++){
			result += "\ntag: " + _nodes[i][k]._tag +
				"  src: " + std::to_string(i) + "  dst: " +
				std::to_string(_nodes[i][k]._dst);
		}
	}
	return result;
}

void 
Graph::make_silly_snake(){
	_nodes_clear(6);
	add_edge(0, 1, "i-see");
	add_edge(1, 2, "the-silly-snake");
	add_edge(2, 3, "i-be");
	add_edge(3, 4, "you-saw-me");
	add_edge(4, 5, "once-like");
	add_edge(5, 0, "kekule");
	//cout << to_string() << endl;
}

void
Graph::make_mr_sticky(){
	_nodes_clear(7);
	add_edge(0, 1, ".");
	add_edge(1, 3, ".");
	add_edge(1, 2, ".");
	add_edge(1, 4, ".");
	add_edge(4, 5, ".");
	add_edge(4, 6, ".");
	//cout << to_string() << endl;
}

void
Graph::make_driftin_dragonfly(){
	_nodes_clear(13);
	add_edge(0, 1, "dis-be-me-head");
	add_edge(1, 2, "me");
	add_edge(1, 5, "dis-be-me");
	add_edge(1, 9, "dis-be-me");
	add_edge(2, 3, "long-tail");
	add_edge(3, 4, "be-dis");
	add_edge(5, 6, "front-right");
	add_edge(6, 7, "me-right");
	add_edge(7, 8, "back");
	add_edge(8, 2, "be-dis");
	add_edge(9, 10, "front-left");
	add_edge(10, 11, "and-left");
	add_edge(11, 12, "back");
	add_edge(12, 2, "be-dis");
	//cout << to_string() << endl;
}

void
Graph::make_slinky_star(){
	_nodes_clear(15);
	add_edge(0, 1, "-");	
	add_edge(0, 3, "-");	
	add_edge(0, 5, "-");	
	add_edge(0, 7, "-");	
	add_edge(0, 9, "-");	
	add_edge(0, 11, "-");	
	add_edge(0, 13, "-");	
	add_edge(1, 2, "-");	
	add_edge(3, 4, "-");	
	add_edge(5, 6, "-");	
	add_edge(7, 8, "-");	
	add_edge(9, 10, "-");	
	add_edge(11, 12, "-");	
	add_edge(13, 14, "-");	
	//cout << to_string() << endl;
}

void
Graph::make_kathy_da_grate(){
	_nodes_clear(15);
	add_edge(0, 1, "-");	
	add_edge(0, 5, "-");	
	add_edge(1, 2, "-");	
	add_edge(1, 7, "-");	
	add_edge(2, 3, "-");	
	add_edge(2, 9, "-");	
	add_edge(3, 4, "-");	
	add_edge(3, 11, "-");	
	add_edge(4, 0, "-");	
	add_edge(4, 13, "-");	
	add_edge(5, 6, "-");	
	add_edge(7, 8, "-");	
	add_edge(9, 10, "-");	
	add_edge(11, 12, "-");	
	add_edge(13, 14, "-");
	//cout << to_string() << endl;	
}

void
Graph::make_dodos_in_space(){
	_nodes_clear(50);
	add_edge(0, 1, "Yippee-Dodo-#0");	
	add_edge(2, 3, "Yippee-Dodo-#2");	
	add_edge(4, 5, "Yippee-Dodo-#4");	
	add_edge(6, 7, "Yippee-Dodo-#6");	
	add_edge(8, 9, "Yippee-Dodo-#8");	
	add_edge(10, 11, "Yippee-Dodo-#10");	
	add_edge(12, 13, "Yippee-Dodo-#12");	
	add_edge(14, 15, "Yippee-Dodo-#14");	
	add_edge(16, 17, "Yippee-Dodo-#16");	
	add_edge(18, 19, "Yippee-Dodo-#18");	
	add_edge(20, 21, "Yippee-Dodo-#20");	
	add_edge(22, 23, "Yippee-Dodo-#22");
	add_edge(24, 25, "Yippee-Dodo-#24");	
	add_edge(26, 27, "Yippee-Dodo-#26");	
	add_edge(28, 29, "Yippee-Dodo-#28");	
	add_edge(30, 31, "Yippee-Dodo-#30");	
	add_edge(32, 33, "Yippee-Dodo-#32");	
	add_edge(34, 35, "Yippee-Dodo-#34");	
	add_edge(36, 37, "Yippee-Dodo-#36");	
	add_edge(38, 39, "Yippee-Dodo-#38");	
	add_edge(40, 41, "Yippee-Dodo-#40");	
	add_edge(42, 43, "Yippee-Dodo-#42");	
	add_edge(44, 45, "Yippee-Dodo-#44");	
	add_edge(46, 47, "Yippee-Dodo-#46");	
	add_edge(48, 49, "Yippee-Dodo-#48");	
	//cout << to_string() << endl;
}

void
Graph::make_purty_pitcher(){
	_nodes_clear(22);
	add_edge(0, 1, "here-i-be");
	add_edge(0, 2, "i-be-millie");
	add_edge(0, 3, ".");
	add_edge(3, 4, ".");
	add_edge(3, 5, ".");
	add_edge(3, 6, ".");
	add_edge(6, 7, ".");
	add_edge(6, 8, ".");
	add_edge(6, 9, ".");
	add_edge(9, 11, ".");
	add_edge(9, 10, ".");
	add_edge(9, 12, ".");
	add_edge(12, 14, ".");
	add_edge(12, 13, ".");
	add_edge(12, 15, ".");
	add_edge(15, 16, ".");
	add_edge(15, 17, ".");
	add_edge(15, 18, ".");
	add_edge(18, 21, ".");
	add_edge(18, 20, ".");
	add_edge(18, 19, ".");
	//cout << to_string() << endl;
}
