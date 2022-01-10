//Student ID: 20447032
//Quest: the complex kiwi

#include <iostream>
#include <string>
#include "Complex.h"

using namespace std;

bool
Complex::operator==(const Complex& that) const {
	if(this->_real == that._real && this->_imag == that._imag){
		return true;
	}
	return false;
}

bool
Complex::operator<(const Complex& that) const {
	return this->norm() < that.norm();
}

Complex
Complex::operator+(const Complex& that) const {
	Complex plus(this->_real + that._real, this->_imag + that._imag);
	return plus;
}

Complex
Complex::operator-(const Complex& that) const {
	Complex minus(this->_real - that._real, this->_imag - that._imag);
	return minus;
}

Complex
Complex::operator*(const Complex& that) const {
	double LHS = (this->_real * that._real) - (this->_imag * that._imag);
	double RHS = (this->_real * that._imag) + (this->_imag * that._real);
	Complex multiply(LHS, RHS);
	return multiply;
}

Complex&
Complex::operator=(const Complex& rhs){
    _real = rhs._real;
    _imag = rhs._imag;
    return *this;
}

Complex
Complex::reciprocal() const {
	double denominator = this->norm_squared();
	if(denominator <= Complex::FLOOR){
		throw Div_By_Zero_Exception();
	}
	Complex reciprocal(this->_real / denominator, -1 *this->_imag / denominator);
	return reciprocal;
}

Complex
Complex::operator/(const Complex& that) const {
	return *this * that.reciprocal();
}

string
Complex::Div_By_Zero_Exception::to_string(){
	return "Divide by zero exception";
}

string
Complex::Div_By_Zero_Exception::what(){
	return to_string();
}

string
Complex::to_string() const {
	char* buf = new char[50];
	sprintf(buf, "(%.11g,%.11g)", _real, _imag);
	return string(buf);
}
