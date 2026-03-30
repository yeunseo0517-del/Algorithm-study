//#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <queue>

char board[1001][1001];
int dist[1001][1001];
int fire[1001][1001];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

#define X first
#define Y second

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c;
	string str;
	queue<pair<int, int>> Q;
	queue<pair<int, int>> Q2;

	cin >> r >> c;

	for (int i = 0; i < r; ++i)
	{
		fill(dist[i], dist[i] + c, -1);
		fill(fire[i], fire[i] + c, -1);
	}

	for (int i = 0; i < r; ++i)
	{
		cin >> str;

		for (int j = 0; j < c; ++j)
		{
			board[i][j] = str[j];

			if (board[i][j] == 'F')
			{
				Q.push({ i,j });
				fire[i][j] = 0;
			}
			else if (board[i][j] == 'J')
			{
				Q2.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}

	while (!Q.empty())
	{
		pair<int, int>cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			if (fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;

			fire[nx][ny] = fire[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}

	while (!Q2.empty())
	{
		pair<int, int>cur = Q2.front();
		Q2.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			{
				cout << dist[cur.X][cur.Y] + 1;
				return 0;
			}
			if (dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (fire[nx][ny] != -1 && fire[nx][ny] <= dist[cur.X][cur.Y] + 1) continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q2.push({ nx,ny });
		}
	}

	cout << "IMPOSSIBLE";
	return 0;
}