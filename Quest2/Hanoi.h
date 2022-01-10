//Student ID: 20447032
//Quest 2: hare today hanoi tomorrow

#ifndef Hanoi_h
#define Hanoi_h

#include <vector>
#include <string>

using namespace std;

class Hanoi {
private:
	int _num_poles;
	int _num_discs;
	
	// TODO: Declare the _cache member using an appropriate
	// level of nesting within std::vectors to put each string
	// of moves. You should be able to access the cache like so:
	vector<vector<vector<string>>> _cache;

	string lookup_moves(int num_discs, int src, int dst);
	string get_moves(int num_discs, int src, int dst, int tmp);

public:
	// Use freebie default constructor
	string solve(int num_discs, int src, int dst, int tmp);

	friend class Tests; // Don't remove this line

};

#endif /* Hanoi_h */
