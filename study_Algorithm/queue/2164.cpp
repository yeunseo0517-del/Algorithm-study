//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		q.push(i);
	}

	while (!q.empty() && q.size() > 1)
	{
		q.pop();
		q.push(q.front());
		if (q.size() == 1)
			break;
		else
			q.pop();
	}

	cout << q.front();
}