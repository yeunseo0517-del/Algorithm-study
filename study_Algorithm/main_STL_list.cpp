//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;
	int n;
	cin >> n;
	while (n--)
	{
		string c;
		cin >> c;
		if (c == "push")
		{
			int x;
			cin >> x;
			s.push(x);
		}
		else if (c == "pop")
		{
			if (s.empty())
				cout << -1 << '\n';
			else
			{
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (c == "size")
		{
			cout << s.size() << '\n';
		}
		else if (c == "empty")
		{
			cout << (int)s.empty() << '\n';
		}
		else if (c == "top")
		{
			if (s.empty())
				cout << -1 << '\n';
			else
				cout << s.top() << '\n';
		}
	}
}