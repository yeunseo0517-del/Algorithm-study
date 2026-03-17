//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <deque>

int t;
deque<int> dq;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		dq.clear();

		bool reverse = false, error = false;

		string arr;
		string func;

		cin >> func;

		int num;

		cin >> num >> arr;

		if (num > 0)
		{
			int x = 0;

			for (auto c : arr)
			{
				if (c >= '0' && c <= '9')
				{
					x = x * 10 + (c - '0');
				}
				else if (c == ',' || c == ']')
				{
					dq.push_back(x);
					x = 0;
				}
			}
		}


		for (auto c : func)
		{
			if (c == 'R')
			{
				reverse = !reverse;
			}
			else if (c == 'D')
			{
				if (!dq.empty())
				{
					if (reverse)
						dq.pop_back();
					else
						dq.pop_front();
				}
				else
				{
					error = true;
					break;
				}
			}
		}

		if (!error)
		{
			cout << "[";

			if (reverse)
			{
				while (!dq.empty())
				{
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty())
						cout << ",";
				}
			}
			else
			{
				while (!dq.empty())
				{
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty())
						cout << ",";
				}

			}
			cout << "]\n";
		}
		else
			cout << "error\n";
	}
}