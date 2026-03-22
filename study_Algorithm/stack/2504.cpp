//#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <stack>
#include <string>

stack<char, int> s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num = 1;
	int sum = 0;
	string str;

	cin >> str;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(')
		{
			s.push(str[i]);
			num *= 2;
		}
		else if (str[i] == '[')
		{
			s.push(str[i]);
			num *= 3;
		}
		else if (str[i] == ')')
		{
			if (s.empty() || s.top() != '(')
			{
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '(')
				sum += num;
			s.pop();
			num / 2;
		}
		else
		{
			if (s.empty() || s.top() != '[')
			{
				cout << '0';
				return 0;
			}
			if (str[i - 1] == '[')
				sum += num;
			s.pop();
			num / 3;
		}
	} 

	if (s.empty())
		cout << sum;
	else
		cout << 0;
}