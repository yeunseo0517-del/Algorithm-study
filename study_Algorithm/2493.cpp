//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

int n;
stack<pair<int, int>> s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int cur;

		cin >> cur;
		
		while (!s.empty() && s.top().first < cur)
			s.pop();

		cout << s.top().second << ' ';

		s.push({cur, i});
	}

}