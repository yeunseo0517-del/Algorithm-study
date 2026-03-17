//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <deque>

int n;
deque<int> DQ;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--)
	{
		string s;
		cin >> s;
		if (s == "push_front")
		{
			int x;
			cin >> x;
			DQ.push_front(x);
		}
		else if (s == "push_back")
		{
			int x;
			cin >> x;
			DQ.push_back(x);
		}
		else if (s == "pop_front")
		{
			if (DQ.empty())
				cout << "-1\n";
			else
			{
				cout << DQ.front() << '\n';
				DQ.pop_front();
			}
		}
		else if (s == "pop_back")
		{
			if (DQ.empty())
				cout << "-1\n";
			else
			{
				cout << DQ.back() << '\n';
				DQ.pop_back();
			}
		}
		else if (s == "size")
		{
			cout << DQ.size() << '\n';
		}
		else if (s == "empty")
		{
			cout << DQ.empty() << '\n';
		}
		else if (s == "front")
		{
			if (DQ.empty())
				cout << "-1\n";
			else
				cout << DQ.front() << '\n';
		}
		else if (s == "back")
		{
			if (DQ.empty())
				cout << "-1\n";
			else
				cout << DQ.back() << '\n';
		}

	}

}