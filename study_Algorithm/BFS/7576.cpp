//#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <queue>

int bfs[1002][1002];
int dist[1002][1002];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> m >> n;
	queue<pair<int, int>> q;

	for(int i=0;i<n;++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> bfs[i][j];
			if (bfs[i][j] == 1)
				q.push({ i,j });
			if (bfs[i][j] == 0)
				dist[i][j] = -1;
		}

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0) continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx,ny });
		}
	}

	int ans = 0;
	for(int i=0;i<n;++i)
		for (int j = 0; j < m; ++j)
		{
			if (dist[i][j] == -1)
			{
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}

	cout << ans;
	return 0;
}