//Student ID: 20447032
//Quest7: an ant a cyana

#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class Queue {
private:
	vector<T> _data;
	size_t _head, _tail;
	static T _sentinel;

public:
	static const int MAX_DISP_ELEMS = 100;

	Queue(size_t size);

	static void set_sentinel(const T& elem) { _sentinel = elem; }
	static T get_sentinel() { return _sentinel; }

	bool is_empty() const;
	size_t size() const {
		if(is_empty()){
			return 0;
		}
		size_t i = _head;
		size_t s = 0;
		while(i != _tail) {
			s++;
			i ++;
			if(i == _data.size()){
				i = 0;
			}
		}
		return s;
	}

	void resize(size_t size);

	const T& peek() const;
	bool dequeue();
	bool enqueue(const T& elem);

	string to_string(size_t limit = MAX_DISP_ELEMS) const;

	friend class Tests; // Don't remove this line
};

template <typename T> T Queue<T>::_sentinel = T();

template <typename T>
Queue<T>::Queue(size_t size) {
	_data.resize(size + 1);
	_head = 0, _tail = 0;
}

template <typename T>
bool Queue<T>::enqueue(const T& elem){
	if(_head != (_tail + 1) % _data.size()){
		_data[_tail] = elem;
		_tail ++;
		if(_tail == _data.size()){
			_tail = 0;
		}
		return true;
	} else {
		return false;
	}
}

template <typename T>
bool Queue<T>::dequeue(){
	if(is_empty()){
		return false;
	} else {
		_head++;
		if(_head == _data.size()){
			_head = 0;
		}
		return true;
	}
}

template <typename T>
const T& Queue<T>::peek() const {
	if(is_empty()){
		return _sentinel;
	}
	return _data[_head];
}

template <typename T>
bool Queue<T>::is_empty() const {
	if(_head == _tail){ return true; }
	return false;
}

template <typename T>
void Queue<T>::resize(size_t size){
	vector<T> new_data;
	new_data.resize(size+1);
	size_t i = _head;
	size_t j = 0;
	while(i != _tail){
		if(j == size){
			break;
		}
		new_data[j] = _data[i];
		i++;
		j++;
		if(i == _data.size()){
			i = 0;
		}
	}
	new_data[j] = _sentinel;
	_data.clear();
	_data = new_data;
	_head =0;
	_tail =j;
}

template <typename T>
void popalot(Queue<T>& q){
	q.resize(0);
}

template <typename T>
string Queue<T>::to_string(size_t lim) const {
	string result = "# Queue - size = " + std::to_string(size()) + "\ndata :";
	size_t i = _head;
	size_t counter = 0;

	while(i != _tail) {
		result += " " + std::to_string(_data[i]);
		i++;
		counter ++;
		if(i == _data.size()){
			i = 0;
		}
		if(counter >= lim && lim != size()){
			result += "...";
			break;
		}
	}
	result += "\n";
	return result;
}

#endif /* Queue_h */
