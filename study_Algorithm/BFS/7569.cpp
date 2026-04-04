//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int board[101][102][102];
int dist[101][102][102];

#define X first
#define Y second

int dirX[6] = { 1,0,-1,0,0,0 };
int dirY[6] = { 0,1,0,-1,0,0 };
int dirZ[6] = { 0,0,0,0, 1, -1 };

int m, n, h;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;
	queue<pair<int, pair<int, int>>> Q;

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < n; ++j)
			fill(dist[i][j], dist[i][j] + m, -1);

	for (int i = 0; i < h; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < m; ++k)
			{
				cin >> board[i][j][k];
				if (board[i][j][k] == 1)
				{
					Q.push({ i,{j,k} });
					dist[i][j][k] = 0;
				}
			}
				
	while (!Q.empty())
	{
		int height = Q.front().first;
		pair<int, int> cur = Q.front().second; Q.pop();

		for (int dir = 0; dir < 6; ++dir)
		{
			int nx = cur.X + dirX[dir];
			int ny = cur.Y + dirY[dir];
			int nz = height + dirZ[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
			if (board[nz][nx][ny] != 0 || dist[nz][nx][ny] != -1) continue;

			board[nz][nx][ny] = 1;
			dist[nz][nx][ny] = dist[height][cur.X][cur.Y] + 1;
			Q.push({ nz, {nx,ny} });
		}
	}
	int maxVal = 0;
	for(int i=0;i<h;++i)
		for(int j=0;j<n;++j)
			for (int k = 0; k < m; ++k)
			{
				if (board[i][j][k] == 0)
				{
					cout << "-1";
					return 0;
				}
				maxVal = max(maxVal, dist[i][j][k]);
			}

	cout << maxVal;
}