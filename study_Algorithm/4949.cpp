//#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <stack>
#include <string>

string str;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (getline(cin, str))
	{
		stack<char> s;

		if (str == ".")
			break;

		bool error = false;

		for (char ch : str)
		{
			if (ch == '(' || ch == '[')
				s.push(ch);
			else if (ch == ')')
			{
				if (s.empty() || s.top() != '(')
				{
					error = true;
					break;
				}
				else
					s.pop();
			}
			else if (ch == ']')
			{
				if (s.empty() || s.top() != '[')
				{
					error = true;
					break;
				}
				else
					s.pop();
			}
		}

		if (error || !s.empty())
			cout << "no\n";
		else
			cout << "yes\n";
	}
}