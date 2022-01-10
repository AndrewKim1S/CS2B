// Student ID: 20447032

#include <iostream>
#include "Playlist.h"
#include <string>

using namespace std;

//Miniquest 1
bool 
Playlist::Song_Entry::set_id(int id){
	if(id >= 0){
		_id = id;
		return true;
	}
	return false;
}

bool 
Playlist::Song_Entry::set_name(string name){
	if(!name.empty()){
		_name = name;
		return true;
	}
	return false;
}

Playlist::Playlist(){
	_head = new Node(Song_Entry(-1, "HEAD"));
	_tail = _head;
	_prev_to_current = _head;
	_size = 0;
}

//Miniquest 2
Playlist::~Playlist(){
	Node* node = _head;
	Node* temp;
	while(node != nullptr){
		temp = node->get_next();
		delete node;
		node = temp;
	}
}

Playlist::Node::~Node(){
	
}

//insert_next and remove_next
Playlist::Node*
Playlist::Node::insert_next(Node *p){
	this->_next = p;
	return p;
}

Playlist::Node*
Playlist::Node::remove_next(){
	Node* temp = this->_next;
	this->_next = this->_next->_next;
	delete temp;
	return this;
}

//Miniquest 3
Playlist* 
Playlist::insert_at_cursor(const Song_Entry& s){
	Node* insert = new Node(s);
	insert->insert_next(_prev_to_current->get_next());
	_prev_to_current->insert_next(insert);
	_size ++;
	if(_head == _tail){
		_tail = _head->get_next();
	}
	return this;	
}

//Miniquest 4
Playlist* 
Playlist::push_back(const Song_Entry& s){
	Node* temp_ = _prev_to_current;
	_prev_to_current = _tail;
	insert_at_cursor(s);
	_tail = _prev_to_current->get_next();
	_prev_to_current = temp_;
	return this;
}

//Miniquest 5
Playlist* 
Playlist::push_front(const Song_Entry& s){
	Node* temp_ = _prev_to_current;
	_prev_to_current = _head;
	insert_at_cursor(s);
	_prev_to_current = temp_;
	return this;
}

//Miniquest 6
Playlist* 
Playlist::advance_cursor(){
	if(_prev_to_current == _tail){
		return nullptr;
	}
	else{
		_prev_to_current = _prev_to_current->get_next();
		return this;
	}
}

//Miniquest 7
Playlist*
Playlist::circular_advance_cursor(){
	if(_prev_to_current == _tail){
		_prev_to_current = _head->get_next();
	}
	else{
		_prev_to_current = _prev_to_current->get_next();
	}
	return this;

}

//Miniquest 8
Playlist::Song_Entry& 
Playlist::get_current_song() const {
	if(_prev_to_current->get_next() == nullptr){
		return _head->get_song();
	}
	return _prev_to_current->get_next()->get_song();
}

//Miniquest 9
Playlist*
Playlist::remove_at_cursor(){
	_prev_to_current->remove_next();
	_size --;
	return this;
}

//Miniquest 10
//Already implemented??

//Miniquest 11
Playlist*
Playlist::rewind(){
	_prev_to_current = _head;
	return this;
}

//Miniquest 12
Playlist*
Playlist::clear(){
	rewind();
	while(_prev_to_current->get_next() != nullptr){
		_head = _prev_to_current->get_next();
		_prev_to_current = nullptr;
		delete _prev_to_current;
		_prev_to_current = _head;
	}
	_prev_to_current = _head;
	_tail = _head;
	_size = 0;
	return this;
}

//Miniquest 13
Playlist::Song_Entry& 
Playlist::find_by_id(int id) const {
	Node* runner = _head;
	while(runner != nullptr){
		if(id == runner->get_song().get_id()){
			return runner->get_song();
		}
		runner = runner->get_next();
	}
	return _head->get_song();
	
}

Playlist::Song_Entry& 
Playlist::find_by_name(string id) const {
	Node* runner = _head;
	while(runner != nullptr){
		if(id == runner->get_song().get_name()){
			return runner->get_song();
		}
		runner = runner->get_next();
	}
	return _head->get_song();
}

//Miniquest 14
string 
Playlist::to_string() const{
	Node* runner = _head->get_next();
	string result = "Playlist: " + std::to_string(get_size()) + " entries.\n";
	
	for(int counter = 0; counter < 25 && runner != nullptr; counter ++){
		result += "{ id: " + std::to_string(runner->get_song().get_id())
 			+ ", name: " + runner->get_song().get_name() + " }";
		if (runner == _prev_to_current){
			result += " [P]";
		}
		if (runner == _tail){
			result += " [T]";
		}
		result += "\n";
		runner = runner->get_next();
	}
	if (get_size() > 25){
		result += "...\n";
	}

	return result;
}
