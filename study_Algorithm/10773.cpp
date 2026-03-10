//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	stack<int> s;
	cin >> k;
	while (k--)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			s.pop();
		}
		else
		{
			s.push(x);
		}
	}

	int sum = 0;
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}

	cout << sum;
}