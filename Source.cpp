#include <vector>
#include <iostream>
#include "CVector.h"
using namespace std;

int CVector::countElementsExemp = 0;
int main() {
	CVector countElementsExemp;
	CVector a = CVector(10);
	CVector c = CVector(12);
	a.setElements(new int[10]{ 2,4,4,11,19,14,12,5,3,5 }, 10); c.setElements(new int[12]{ 5,5,1,5,11,17,2,6,10,12,23,13 }, 12);
	a.getElements(); c.getElements();
	cout <<"Sum of elements: "<< a.elementsCount() + c.elementsCount() <<  endl;
	cout << "Max element & Min element of first vector: " << a.max() <<" & " <<  a.min() << endl;
	cout << "Max element & Min element of second vector: " << c.max() <<" & " << c.min() << endl;
	cout << "Average of elements in first vector: " << a.sumElements() / a.elementsCount() << endl;
	cout << "Average of elements in second vector: " << c.sumElements() / c.elementsCount() << endl;
	cout << "Count elements in first vector bigger than number: " << a.countElementBiggerThanNumber(7) << endl;
	cout << "Count elements in second vector bigger than number: " << c.countElementBiggerThanNumber(10) << endl;
	cout << "Multiply of elements in first vector: " << a.multiplyElements() << endl;
	cout << "Multiply of elements in second vector: " << c.multiplyElements() << endl;
	CVector  ssm = a + c;
	ssm.getElements();
	CVector ssa = a - c;
	ssa.getElements(); 
	cout << countElementsExemp.instanceCount() << endl;
	system("pause");
	return 0;
}	