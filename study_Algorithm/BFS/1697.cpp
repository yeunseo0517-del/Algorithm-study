//#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <queue>

int cnt[100002];

queue<int> Q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		fill(cnt, cnt + 100001, -1);

	cnt[n] = 0;
	Q.push(n);

	while (cnt[m] == -1)
	{
		int cur = Q.front();
		Q.pop();

		for (int nx : {cur - 1, cur + 1, 2 * cur})
		{
			if (nx < 0 || nx > 100000) continue;
			if (cnt[nx] != -1) continue;

			cnt[nx] = cnt[cur] + 1;
			Q.push(nx);
		}
	}
	cout << cnt[m];
}