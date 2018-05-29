#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

// второе задание
class Complex {
private:
	double re;
	double im;


public:
	//конструкторы
	Complex();
	Complex(double re, double im);
	Complex(const Complex &obj);

	friend ostream& operator << (ostream& os, const Complex& complex);
	friend istream& operator >> (istream& is, Complex& complex);

	void init(double re, double im);

	// function for re
	void set_re(double re);
	double get_re();
	void input_re();

	// function for im
	void set_im(double im);
	double get_im();
	void input_im();

	//перегрузка операторов
	Complex operator + (Complex c2);
	Complex operator - (Complex c2);
	Complex operator* (Complex c2);
	Complex operator/ (Complex c2);
	Complex operator* (double mn);
	Complex operator/ (double mn);
	Complex operator = (Complex c2);
	bool operator == (Complex c2);
	bool operator != (Complex c2);


};
//операторы вывода
ostream& operator << (ostream& os, const Complex& complex) {
	if (complex.re != 0) {
		if (complex.im != 0) {
			if (complex.im > 0) {
				os << to_string(complex.re) + '+' + to_string(complex.im) + "i";
			}
			else
				os << to_string(complex.re) + to_string(complex.im) + "i";
		}
		else
			os << to_string(complex.re);
	}
	else {
		if (complex.im != 0) {
			os << to_string(complex.im) + "i";
		}
		else
			os << 0;
	}
	return os;
}
istream& operator >> (istream& is, Complex& complex) {
	cout << "¬ведите Re(z): ";
	is >> complex.re;
	cout << "¬ведите Im(z): ";
	is >> complex.im;
	return is;
}

//реализаци€ методов
Complex::Complex() {
}
Complex::Complex(double re, double im) {
	this->re = re;
	this->im = im;
}
Complex::Complex(const Complex &obj) {

}
void Complex::init(double re, double im) {
	this->re = re;
	this->im = im;
}

void Complex::set_re(double re) {
	this->re = re;
}
double Complex::get_re() {
	return this->re;
}
void Complex::input_re() {
	cout << "Input Re: ";
	cin >> this->re;
	cout << re << endl;
}
void Complex::set_im(double im) {
	this->im = im;
}
double Complex::get_im() {
	return this->im;
}
void Complex::input_im() {
	cout << "Input im: ";
	cin >> this->im;
	cout << im << endl;
}

Complex Complex::operator + (Complex c2) {
	Complex resultComplex;

	resultComplex.set_re(this->get_re() + c2.get_re());
	resultComplex.set_im(this->get_im() + c2.get_im());

	return resultComplex;
}
Complex Complex::operator - (Complex c2) {
	Complex resultComplex;
	resultComplex.set_re(this->get_re() - c2.get_re());
	resultComplex.set_im(this->get_im() - c2.get_im());
	return resultComplex;
}
Complex Complex::operator* (Complex c2) {
	Complex resultComplex;
	resultComplex.set_re((this->get_re()*c2.get_re()) - (this->get_im()*c2.get_im()));
	resultComplex.set_im((this->get_im()*c2.get_re()) - (this->get_re()*c2.get_im()));
	return resultComplex;
}
Complex Complex::operator/ (Complex c2) {
	Complex resultComplex;
	resultComplex.set_re(((this->get_re()*c2.get_re()) + (this->get_im()*c2.get_im())) / (pow(c2.get_re(), 2) + pow(c2.get_im(), 2)));
	resultComplex.set_im(((this->get_im()*c2.get_re()) - (this->get_re()*c2.get_im())) / (pow(c2.get_re(), 2) + pow(c2.get_im(), 2)));
	return resultComplex;
}
Complex Complex::operator* (double mn) {
	Complex resultComplex;
	resultComplex.set_re(this->get_re()*mn);
	resultComplex.set_im(this->get_im()*mn);
	return resultComplex;
}
Complex Complex::operator/ (double mn) {
	Complex resultComplex;
	resultComplex.set_re(this->get_re() / mn);
	resultComplex.set_im(this->get_im() / mn);
	return resultComplex;
}
Complex Complex::operator = (Complex c2) {
	this->set_re(c2.get_re());
	this->set_im(c2.get_im());
	return *this;
}
bool Complex::operator == (Complex c2) {
	if (this->get_re() != c2.get_re())
		return false;
	else if (this->get_im() != c2.get_im())
		return false;
	return true;
}
bool Complex::operator != (Complex c2) {
	if (this->get_re() == c2.get_re())
		return false;
	else if (this->get_im() == c2.get_im())
		return false;
	return true;
}

