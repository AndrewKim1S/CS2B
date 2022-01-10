#include <iostream>
#include "Hanoi.h"

using namespace std;

int main(){

	Hanoi test;
	cout << test.solve(0, 1,2,3) << endl;
	cout << test.solve(1, 1,2,3) << endl;

	cout << test.solve(2, 1,2,3) << endl;
	cout << test.solve(3, 1,2,3) << endl;
	
	return 0;
}
