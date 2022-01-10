
#include "Automaton.h"
#include <iostream>

using namespace std;

int main(){

	Automaton a1(3,155);
	vector<int> test = {1,0,0,1};
	

	vector <int> next_gen;
	a1.make_next_gen(test, next_gen);
	cout << "current generation:" << a1.generation_to_string(test,5) << endl;
	//cout << "   next generation:" << a1.generation_to_string(next_gen,11) << endl;
	string result = a1.get_first_n_generations( 5, 9);
	cout << result;
	return 0;

}
