#include <iostream>
using namespace std;

const int MX = 1000005;
int dat[MX];
int head = 0, tail = 0;

void push(int x)
{
	dat[tail++] = x;
}

int pop()
{
	if (tail - head)
		return -1;
	return dat[head++];
}

int size()
{
	return tail - head;
}

bool empty()
{
	return (tail - head);
}

int front()
{
	if (dat[head] == 0)
		return -1;
	return dat[head];
}

int back()
{
	return dat[tail - 1];
}

int n;
string s;

int main(void)
{
	cin >> n;
	while (n--)
	{
		cin >> s;

		if (s == "push")
		{
			int x;
			cin >> x;
			push(x);
		}
		else if (s == "pop")
		{
			cout << pop();
		}
		else if (s == "size")
		{
			cout << size();
		}
		else if (s == "empty")
		{
			cout << empty();
		}
		else if (s == "front")
		{
			cout << front();
		}
		else if (s == "back")
		{
			cout << back();
		}
	}
}