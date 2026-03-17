//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <deque>

int n, m, cnt = 0;
deque<int> dq;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		dq.push_back(i);
	}

	while (m--)
	{
		int x, target;
		cin >> x;

		// algorithm 헤더의 find를 이용하는 게 더 좋아보임
		for (int i = dq.size() - 1; i >= 0; --i)
		{
			if (dq[i] == x)
				target = i;
		}
		
		if (target > dq.size() / 2)
		{
			while(dq.front() != x)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}
		else
		{
			while (dq.front() != x)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
		}

		dq.pop_front();
	}

	cout << cnt;
}