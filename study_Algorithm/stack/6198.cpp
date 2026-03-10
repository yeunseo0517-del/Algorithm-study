//#include <bits/stdc++.h>
#include <iostream>
#include <stack>
using namespace std;

int n;
long long sum = 0;
stack<int> s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int cur;

		cin >> cur;

		while (!s.empty() && s.top() <= cur)
			s.pop();

		sum += s.size();

		s.push(cur);
	}
	cout << sum;
}