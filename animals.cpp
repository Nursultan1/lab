#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Animals {
private:
	string name;
	string habitat; //среда обитания (домашняя или дикий)
	double weight; //вес

public:
	void init(string name, string habitat, double weigth) {
		this->habitat = habitat;
		this->weight = weigth;
		this->name = name;
	}

	void set_name(string name) {
		this->name = name;
	}
	string get_name() {
		return this->name;
	}
	void input_name() {
		cout << "Input name: ";
		cin >> this->name;
		cout << name << endl;
	}

	// function for habitat
	void set_habitat(string habitat) {
		this->habitat = habitat;
	}
	string get_habitat() {
		return this->habitat;
	}
	void input_habitat() {
		cout << "Input habitat: ";
		cin >> this->habitat;
		cout << habitat << endl;
	}

	// function for weight
	void set_weight(double weight) {
		this->weight = weight;
	}
	double get_weight() {
		return this->weight;
	}
	void input_weight() {
		cout << "Input weight: ";
		cin >> this->weight;
		cout << weight << endl;
	}


};

class Dog :public Animals {
private:
	string breed;
	string owner;

public:
	void init(string name, string habitat, double weigth, string owner, string breed) {
		Animals::init(name, habitat, weigth);
		this->breed = breed;
		this->owner = owner;
	}

	// function for breed
	void set_breed(string breed) {
		this->breed = breed;
	}
	string get_breed() {
		return this->breed;
	}
	void input_breed() {
		cout << "Input breed: ";
		cin >> this->breed;
		cout << breed << endl;
	}

	// function for owner
	void set_owner(string owner) {
		this->owner = owner;
	}
	string get_owner() {
		return this->owner;
	}
	void input_owner() {
		cout << "Input owner: ";
		cin >> this->owner;
		cout << owner << endl;
	}

};

class Wolf :public Animals {
private:
	string color;
	int  year;


public:

	void init(string name, string habitat, double weigth, string color, int year) {
		Animals::init(name, habitat, weigth);
		this->color = color;
		this->year = year;
	}


	// function for color
	void set_color(string color) {
		this->color = color;
	}
	string get_color() {
		return this->color;
	}
	void input_color() {
		cout << "Input color: ";
		cin >> this->color;
		cout << color << endl;
	}

	// function for year
	void set_year(int year) {
		this->year = year;
	}
	int get_year() {
		return this->year;
	}
	void input_year() {
		cout << "Input year: ";
		cin >> this->year;
		cout << year << endl;
	}
};