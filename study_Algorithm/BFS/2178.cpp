//#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <queue>

int bfs[102][102];
int dis[102][102];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

#define X first
#define Y second

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	string s;

	for (int i = 0; i < n; ++i)
	{
		cin >> s;

		for (int j = 0; j < m; ++j)
		{
			bfs[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; ++i)
		fill(dis[i], dis[i] + m, -1);

	queue<pair<int, int>> Q;

	Q.push({ 0,0 });
	dis[0][0] = 1;

	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (!bfs[nx][ny] || dis[nx][ny] != -1) continue;

			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}

	cout << dis[n - 1][m - 1];
}