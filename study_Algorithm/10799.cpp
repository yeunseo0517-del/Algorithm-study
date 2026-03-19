//#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <stack>
#include <string>

stack<char> s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num = 0;
	string str;

	cin >> str;

	bool isLastRight = false;

	for (char c : str)
	{
		if (c == '(')
		{
			s.push(c);
			isLastRight = false;
		}
		else if (c == ')')
		{
			if (!isLastRight)
			{
				s.pop();
				num += s.size();

				isLastRight = true;
			}
			else if (isLastRight)
			{
				++num;
				s.pop();
			}
		}
	}

	cout << num;
}