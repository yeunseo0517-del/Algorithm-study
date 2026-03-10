#include <iostream>
#include "MyStack.h"

MyStack::MyStack()
	: data(nullptr), count(0), max(2)
{
	data = new int[max];
}

MyStack::~MyStack()
{
	delete[] data;
}

bool MyStack::empty()
{
	return !count;

}


void MyStack::resize(int _iSize)
{
	if (max >= _iSize)
		return;

	int* dNew = new int[_iSize];

	for (int i = 0; i < count; ++i)
	{
		dNew[i] = data[i];
	}

	delete[] data;

	data = dNew;

	max = _iSize;
}

int MyStack::top()
{
	return data[count - 1];
}

void MyStack::push(int x)
{
	if (count == max)
		resize(max * 2);
	data[count++] = x;
}

void MyStack::pop()
{
	if (empty())
		return;
	count--;
}

int MyStack::size()
{
	return count;
}