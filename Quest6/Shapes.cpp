//Student ID: 20447032
//Quest 6: magnum octopus

#include "Shapes.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

Screen::Screen(size_t w, size_t h){
	if(w == 0 || h == 0){
		return;
	}
	_pix.resize(h);
	for(size_t i = 0; i < h ; i++){
		_pix[i].resize(w);
	}
	set_h(h);
	set_w(w);
}

void
Screen::fill(char c){
	for(size_t i = 0; i < _h; i++){
		for(size_t j = 0; j < _w; j++){
			_pix[i][j] = c;
		}
	}
}

string
Screen::to_string() const {
	string result = "";
	for(size_t i = _h; i > 0; i--){
		for(size_t j = 0; j < _w; j++){
			result += _pix[i-1][j];
		}
		result += "\n";
	}
	return result;
}

bool
Point::draw(Screen &screen, char c){
	if(this->_x < 0 || this->_y < 0){
		return false;
	}
	if(this->_x <= screen.get_w() - 1 && this->_y <= screen.get_h()-1){
		vector<vector<char>> &pix = screen.get_pix();
		pix[_y][_x] = c;
	}
	return true;
}

bool
Line::draw_by_x(Screen &scr, char ch, size_t x1, size_t y1, size_t x2, size_t y2){
	if(x1 > x2){
		return draw_by_x(scr, ch, x2, y2, x1, y1);
	}
	double dy = ((double) y2-y1)/((double) x2-x1);
	bool contain = true;
	double x = x1, y= y1;
	while (x <= x2){
		contain &= Point((size_t) x, (size_t) y).draw(scr, ch);
		x += 1; y += dy;
	}
	return contain;
}

bool
Line::draw_by_y(Screen &scr, char ch, size_t x1, size_t y1, size_t x2, size_t y2){
	if(y1 > y2){
		return draw_by_y(scr, ch, x2, y2, x1, y1);
	}
	double dx = ((double) x2-x1)/((double) y2-y1);
	bool contain = true;
	double x = x1, y= y1;
	while (y <= y2){
		contain &= Point((size_t) x, (size_t) y).draw(scr, ch);
		x += dx; y += 1;
	}
	return contain;
}

bool
Line::draw(Screen &scr, char ch){
	double slope = ((double)_y1-(double)_y2)/((double)_x1-(double)_x2);
	if(abs(slope) > 1){
		return draw_by_y(scr, ch, _x1, _y1, _x2, _y2);
	} else {
		return draw_by_x(scr, ch, _x1, _y1, _x2, _y2);
	}
}

bool
Quadrilateral::draw(Screen &scr, char ch){
	bool contain = true;
	Line one(_x1,_y1, _x2,_y2);
	Line two(_x2,_y2, _x3,_y3);
	Line three(_x3,_y3, _x4,_y4);
	Line four(_x4,_y4, _x1,_y1);
	contain &= one.draw(scr, ch); 
	contain &= two.draw(scr, ch);
	contain &= three.draw(scr, ch);
	contain &= four.draw(scr, ch);
	return contain;
}

Stick_Man::Stick_Man(size_t x, size_t y, size_t w, size_t h){
	_parts.clear();
	_x = x;
	_y = y;
	_h = h;
	_w = w;
	if(h == 0 || h == 1){
		_h = DEFAULT_H;
	}
	if(w == 0 || w == 1){
		_w = DEFAULT_W;
	}

	Upright_Rectangle *head = new Upright_Rectangle(_x+0,y+_h/2, x+_w-1,y+_h-1);
	_parts.push_back(head);
	Line *torso = new Line(_x+_w/2,_y+_h/2, _x+_w/2,_y+_h/4);
	_parts.push_back(torso);
	Line *leftarm = new Line(_x+_w/2,_y+_h/2, _x+_w/4,_y+_h/4);
	_parts.push_back(leftarm);
	Line *rightarm = new Line(_x+_w/2,_y+_h/2, _x+3*_w/4,_y+_h/4);
	_parts.push_back(rightarm);
	Line *leftleg = new Line(_x+_w/2,_y+_h/4, _x,_y);
	_parts.push_back(leftleg);
	Line *rightleg = new Line(_x+_w/2,_y+_h/4, _x+_w-1,_y);
	_parts.push_back(rightleg);
}

bool
Stick_Man::draw(Screen &scr, char ch){
	for(size_t i = 0; i < _parts.size(); i++){
		_parts[i]->draw(scr, ch);
	}
	return true;
}

Stick_Man::~Stick_Man(){
	for(size_t i = 0; i < _parts.size(); i++){
		delete _parts[i];
	}
}
