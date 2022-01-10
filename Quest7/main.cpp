#include <iostream>
#include "Queue.h"

using namespace std;

int main(){
	Queue<int> list(10);
	Queue<int>::set_sentinel(9999);

	list.enqueue(1);
	list.enqueue(2);
	list.enqueue(3);
	list.enqueue(4);
	list.enqueue(5);
	list.enqueue(6);
	list.enqueue(7);
	cout << list.to_string(10) << endl;
	list.resize(5);
	cout << list.to_string(10) << endl;
	
	popalot(list);
	cout << list.peek() << endl;
	
	return 0;
}
