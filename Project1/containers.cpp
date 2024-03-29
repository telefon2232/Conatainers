#include "Containers.h"
#include <iostream>
MyArray::MyArray()
{
	size = 0;
}

MyArray::MyArray(int n)
{
	size = n;
	ar = new int[size];
	for (int i = 0;i < size;i++) {
		ar[i] = 0;
	}

}

MyArray::MyArray(const MyArray & arq)
{
	size = arq.size;
	ar = new int[size];
	
	if (arq.getCapacity() == getCapacity()) {

		for (int i = 0;i < size;i++) {
			ar[i] = arq.ar[i];
		}
	}
}

int MyArray::getSize() const
{

	return size;

}

int MyArray::getCapacity() const
{
	return size;
}

void MyArray::show() const
{
	for (int i = 0;i < size;i++) {
		std::cout <<   *(ar+i)<<" ";

	}
}

void MyArray::addCapacity(int n)
{
	MyArray mas = *this;
	delete[] ar;
	size += n;
	ar = new int[size];

	for (int i = 0; i < size; i++) {
		ar[i] = mas.ar[i];
	}
	for (int i = size - n; i < size; i++) {
		ar[i] = 0;
	}
}

int & MyArray::operator[](int index)
{

	return ar[index];
}


MyArray & MyArray::operator=(const MyArray & arq)
{
	if (*ar == arq) {
		return ar;
	}
	delete[] ar;
	size = arq.getSize();
	int *ar = new int[size];
	for (int i = 0; i < size;i++) {
		ar[i] = arq.ar[i];
	}
	return *this;
}

MyArray::~MyArray()
{
	delete[] ar;
}

Container::~Container()
{
	size = 0;
}