#pragma once
#include <iostream>
#include <vector>
using namespace std;

class CVector {
	int size, i;
	int* elements;
	static int countElementsExemp;
public:
	CVector() {
		size = 100;
		elements = new int[100];
	};
	CVector(int _size) {
		i = 0;
		size = _size;
		elements = new int[_size];
	}
	~CVector() { delete[] elements; }
	CVector(const CVector & cvector) {
		*this = cvector;
	}
	CVector& operator=(const CVector & cvector) {
		if (this != &cvector) {
			delete[] elements;
			size = cvector.size;
			elements = new int[size];
			for (int i = 0; i < size; i++) {
				elements[i] = cvector.elements[i];
			}
		}
		return *this;
	}
	CVector operator+(const CVector & cvector) {
		int* mass;
		int tempsize, minSize;
		if (size > cvector.size) {
			tempsize = size;
			minSize = cvector.size;
		}
		else if (size < cvector.size) {
			tempsize = cvector.size;
			minSize = size;
		}
		else {
			tempsize = size;
			minSize = size;
		}
		auto cfv = new CVector(tempsize);
		mass = new int[tempsize];
		for (i = 0; i < tempsize; i++) {
			if (i < minSize) {
				mass[i] = elements[i] + cvector.elements[i];
			}
			else if (size < cvector.size) mass[i] = cvector.elements[i];
			else mass[i] = elements[i];
		}
		cfv->setElements(mass, tempsize);
		delete[] mass;
		return *cfv;
	}
	CVector operator-(const CVector & cvector) {
		int* mass;
		int tempsize, minSize;
		if (size > cvector.size) {
			tempsize = size;
			minSize = cvector.size;
		}
		else if (size < cvector.size) {
			tempsize = cvector.size;
			minSize = size;
		}
		else {
			tempsize = size;
			minSize = size;
		}
		auto cfv = new CVector(tempsize);
		mass = new int[tempsize];
		for (i = 0; i < tempsize; i++) {
			if (i < minSize) {
				mass[i] = elements[i] - cvector.elements[i];
			}
			else if (size < cvector.size) mass[i] = cvector.elements[i];
			else mass[i] = elements[i];
		}
		cfv->setElements(mass, tempsize);
		delete[] mass;
		return *cfv;
	}
	bool setElements(int* vals, int _size) {
		if (_size > size) return false;
		for (int k = 0; k < size; k++) {
			if (k < _size) elements[k] = vals[k];
			else elements[k] = 0;
			i++;
		}
		return true;
	}
	int min() {
		int min = elements[0];
		for (int i = 1; i < size; i++) {
			if (elements[i] < min) {
				min = elements[i];
			}
		}
		return min;
	}
	int max() {
		int max = elements[0];
		for (int i = 1; i < size; i++) {
			if (elements[i] > max) {
				max = elements[i];
			}
		}
		return max;
	}
	int sumElements() {
		int sumElements = 0;
		for (int i = 0; i < size; i++) {
			sumElements += elements[i];
		}
		countElementsExemp +=i;
		return sumElements;
	}
	int multiplyElements() {
		int multiplyElements = 1;
		for (int i = 0; i < size; i++) {
			multiplyElements *= elements[i];
		}
		return multiplyElements;
	}
	int countElementBiggerThanNumber(int num) {
		int count = 0;
		for (int i = 0; i < size; i++) {
			if (elements[i] > num) count++;
		}
		return count;
	}
	void add(int val) {
		if (i < size) {
			elements[i] = val;
			i++;
		}
	}
	void getElements() {
		for (int k = 0; k < size; k++) {
			cout << elements[k] << " ";
		}
		cout << endl;
	}
	int elementsCount() {
		return i;
	}
	static int instanceCount() {
		return countElementsExemp;
	}
};