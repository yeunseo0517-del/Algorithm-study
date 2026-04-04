//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

char board[101][101];
bool vis[101][101];

#define X first
#define Y second

int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };

int n, normal = 0, colorBlind = 0;

void BFS(int x, int y)
{
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	vis[x][y] = true;

	while (!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.X + dirX[dir];
			int ny = cur.Y + dirY[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (board[nx][ny] != board[x][y] || vis[nx][ny]) continue;

			vis[nx][ny] = true;
			Q.push({ nx,ny });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0;i<n;++i)
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}

	for(int i=0;i<n;++i)
		for (int j = 0; j < n; ++j)
		{
			if (vis[i][j]) continue;

			normal++;
			BFS(i, j);
		}

	for (int i = 0; i < n; ++i)
		fill(vis[i], vis[i] + n, false);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (board[i][j] == 'G')
				board[i][j] = 'R';

	for(int i=0;i<n;++i)
		for (int j = 0; j < n; ++j)
		{
			if (vis[i][j]) continue;

			colorBlind++;

			BFS(i, j);
		}

	cout << normal << ' ' << colorBlind;
}