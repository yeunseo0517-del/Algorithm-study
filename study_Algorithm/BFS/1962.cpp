//#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <queue>

#define x first
#define y second

int bfs[502][502];
int vis[502][502];

int xdat[4] = { 1, 0, -1, 0 };
int ydat[4] = { 0, 1, 0, -1 };

int num = 0, mx = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> bfs[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (vis[i][j] || !bfs[i][j]) continue;

			queue<pair<int, int>> Q;

			num++;

			Q.push({ i,j });
			vis[i][j] = 1;

			int now = 0;

			while (!Q.empty())
			{
				pair<int, int> cur = Q.front();
				Q.pop();
				now++;

				for (int dir = 0; dir < 4; ++dir)
				{
					int nx = cur.x + xdat[dir];
					int ny = cur.y + ydat[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || !bfs[nx][ny]) continue;

					vis[nx][ny] = 1;

					Q.push({ nx,ny });
				}
			}
			
			mx = (now > mx) ? now : mx;
		}
	}

	cout << num << '\n' << mx;
}