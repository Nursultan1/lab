// vector.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>


using namespace std;


template <typename T>
class Vector
{
private:
	T * _array;
	int _arraySize;
public:
	Vector()
	{
		this->_arraySize = 0;
		this->_array = new T[this->_arraySize];
	}
	Vector(int size)
	{
		if (size >= 0) {
			this->_arraySize = size;
			this->_array = new T[this->_arraySize];
		}
		else {
			cout << "–азмер вектора не может быт отрицательным" << endl;
			this->_arraySize = 0;
			this->_array = new T[this->_arraySize];
		}

	}
	Vector(T* v, int size)
	{
		this->_arraySize = size;
		this->_array = new T[this->_arraySize];
		this->_array = v;
	}
	Vector(const Vector& v)
	{
		this->_arraySize = v._arraySize;
		this->_array = new T[this->_arraySize];
		for (int index = 0; index < this->_arraySize; index++)
		{
			this->_array[index] = v._array[index];
		}
	}
	~Vector()
	{

	}

	friend std::ostream& operator << <T>(std::ostream& out, const Vector<T> &);
	friend std::istream& operator>> <T>(std::istream& in, Vector<T> &);


	bool new_size(int new_size) {
		if (new_size<0) {
			return false;
		}
		if (this->_arraySize != new_size) {
			T *_result = new T[new_size];
			int s = (this->_arraySize < new_size) ? this->_arraySize : new_size;
			for (int index = 0; index < s; index++) {
				_result[index] = this->_array[index];
			}
			delete[] this->_array;
			this->_array = _result;
			this->_arraySize = new_size;
		}
		return true;
	}
	void push_back(T data)
	{
		cout << "Push_back: size:" << endl << this->_arraySize << endl;
		T *_result = new T[++this->_arraySize];

		for (int index = 0; index < this->_arraySize; index++)
		{
			if (index != this->_arraySize - 1)
			{
				_result[index] = this->_array[index];
			}
			else
			{
				_result[index] = data;
				break;
			}
		}
		delete[] this->_array;
		this->_array = _result;
		cout << "Push_backen: size:" << endl << this->_arraySize << endl;
	}

	T pop()
	{
		return this->popIndex(this->_arraySize - 1);
	}

	void clear()
	{
		if (this->_array != NULL)
		{
			::ZeroMemory(this->_array, this->_arraySize);
		}
		this->_arraySize = 0;
		this->_array = new T[this->_arraySize];
	}

	T operator [](int index)
	{
		return this->_array[index];
	}

	int size()
	{
		return this->_arraySize;
	}

	void pushIndex(T data, int index)
	{
		int oldSize = this->_arraySize;

		this->_arraySize = (this->_arraySize >= index) ? (++this->_arraySize) : (this->_arraySize + (index - this->_arraySize));

		T *_result = new T[this->_arraySize];

		int arrIndex = 0;

		for (int index2 = 0; index2 < this->_arraySize; index2++)
		{
			if (index2 == index)
			{
				_result[index2] = data;
				continue;
			}

			if (arrIndex != oldSize)
			{
				_result[index2] = this->_array[arrIndex++];
			}
		}
		delete[] this->_array;
		this->_array = _result;
	}

	T popIndex(int index)
	{
		T *_result = new T[--this->_arraySize];

		T resItem;

		int resIndex = 0;

		for (int index2 = 0; index2 < this->_arraySize + 1; index2++)
		{
			T item = this->_array[index2];

			if (index == index2)
			{
				resItem = item;
				continue;
			}
			_result[resIndex++] = this->_array[index2];
		}
		delete[] this->_array;
		this->_array = _result;
		return resItem;
	}

	template <typename T>
	Vector operator+(const Vector<T>& v2) {
		Vector<T> tmp;
		if (this->_arraySize == v2._arraySize) {
			for (int index = 0; index < this->_arraySize; index++) {
				tmp.push_back(this->_array[index] + v2._array[index]);
			}
		}
		else {
			int size = (this->_arraySize > v2._arraySize) ? v2._arraySize : this->_arraySize;
			for (int index = 0; index < size; index++) {
				tmp.push_back(this->_array[index] + v2._array[index]);
			}
		}
		return tmp;
	}


	template <typename T>
	Vector operator-(const Vector<T>& v2) {
		Vector<T> tmp;
		if (this->_arraySize == v2._arraySize) {
			for (int index = 0; index < this->_arraySize; index++) {
				tmp.push_back(this->_array[index] - v2._array[index]);
			}
		}
		else {
			int size = (this->_arraySize > v2._arraySize) ? v2._arraySize : this->_arraySize;
			for (int index = 0; index < size; index++) {
				tmp.push_back(this->_array[index] - v2._array[index]);
			}
		}
		return tmp;
	}

	Vector operator * (double d) {
		Vector<T> tmp;
		for (int index = 0; index < this->_arraySize; index++) {
			tmp.push_back(d* this->_array[index]);
		}
		return tmp;
	}

	Vector operator / (double d) {
		Vector<T> tmp;
		for (int index = 0; index < this->_arraySize; index++) {
			tmp.push_back(this->_array[index] / d);
		}
		return tmp;
	}

	template <typename T>
	T operator*(const Vector<T>& v2) {
		T tmp = 0;
		if (this->_arraySize == v2._arraySize) {
			for (int index = 0; index < this->_arraySize; index++) {
				tmp += this->_array[index] * v2._array[index];
			}
		}
		else {
			int s = (this->_arraySize > v2._arraySize) ? v2._arraySize : this->_arraySize;

			for (int index = 0; index < s; index++) {
				tmp += this->_array[index] * v2._array[index];
			}
		}
		return tmp;
	}
};

template <typename T>
ostream& operator << (std::ostream& out, const Vector<T> &v)
{
	cout << "—одержимое вектора:" << endl;
	for (int index = 0; index < v._arraySize; index++) {
		out << v._array[index] << "\t";
	}
	return out;
}

template <typename T>
istream& operator >> (std::istream& in, Vector<T> &v)
{
	cout << "¬ведите данные дл€ вектора: " << endl;
	for (int index = 0; index < v._arraySize; index++) {
		in >> v._array[index];
		cout << endl;
	}
	return in;
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	Vector<int> vect(6);//инициализаци€ вектора заданной длины
	cin >> vect; //«аполнени€ вектора
	cout << endl << vect << endl; //вывод
	cout << endl << "–азмер вектора:" << vect.size() << endl; //размер
	cout << endl << "ѕолучает последний:" << vect.size() << endl; //размер


	system("pause");
	return 0;
}

