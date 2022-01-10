//Student ID: 20447032
//Quest 2: hare today hanoi tomorrow

#include <iostream>
#include <vector>
#include <string>
#include "Hanoi.h"

using namespace std;

string
Hanoi::get_moves(int num_discs, int src, int dst, int tmp){

	if(_cache.size() < unsigned(num_discs) + 1){
		_cache.resize(num_discs + 1);
	}
	if(_cache[num_discs].size() < unsigned(src) + 1){
		_cache[num_discs].resize(src + 1);
	}
	if(_cache[num_discs][src].size() < unsigned(dst) + 1){
		_cache[num_discs][src].resize(dst + 1);
	}

	string look = lookup_moves(num_discs, src, dst);
	if(!look.empty()){
		return look;
	}

	string result;
	if(num_discs == 0){
		_cache[0][src][dst] = "";
		return "";
	}
	if(num_discs == 1){
		string value = to_string(src) + "->" + to_string(dst) + "\n";
		_cache[num_discs][src][dst] = value;
		return value;
	} 
	result = get_moves(num_discs - 1, src, tmp, dst) + 
		get_moves(1, src, dst, tmp) + 
		get_moves(num_discs -1, tmp, dst, src);
	
	if(_cache[num_discs - 1].size() > 0){
		_cache[num_discs-1].clear();
	}
	_cache[num_discs][src][dst] = result;
	return result;
}

string
Hanoi::lookup_moves(int num_discs, int src, int dst){
	
	return _cache[num_discs][src][dst];
}

string
Hanoi::solve(int num_discs, int src, int dst, int tmp){
	string result = "# Below, 'A->B' means 'move the top disc on pole A to pole B'\n";
	result += get_moves(num_discs, src, dst, tmp);
	return result;
}
