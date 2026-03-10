#pragma once
class MyStack
{
private:
	int* data;
	int count;
	int max;

public:
	MyStack();
	~MyStack();

	void resize(int _iSize);
	int top();
	void push(int x);
	void pop();
	bool empty();
	int size();
};