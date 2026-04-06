//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

char board[1002][1002];
int fire[1002][1002];
int dist[1002][1002];

#define X first
#define Y second

int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };

int t, w, h;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		bool isEscape = false;

		cin >> w >> h;
		queue<pair<int, int>> Q, Q2;

		for (int i = 0; i < h; ++i)
			fill(fire[i], fire[i] + w, -1);
		for (int i = 0; i < h; ++i)
			fill(dist[i], dist[i] + w, -1);

		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
			{
				cin >> board[i][j];

				if (board[i][j] == '*')
				{
					Q.push({ i,j });
					fire[i][j] = 0;
				}
				else if (board[i][j] == '@')
				{
					Q2.push({ i,j });
					dist[i][j] = 0;
				}
			}

		while (!Q.empty())
		{
			pair<int, int> cur = Q.front(); Q.pop();

			for (int dir = 0; dir < 4; ++dir)
			{
				int nx = cur.X + dirX[dir];
				int ny = cur.Y + dirY[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (fire[nx][ny] != -1 || board[nx][ny] == '#') continue;

				fire[nx][ny] = fire[cur.X][cur.Y] + 1;
				Q.push({ nx,ny });
			}
		}
		
		while (!Q2.empty() && !isEscape)
		{
			pair<int, int> cur = Q2.front(); Q2.pop();

			for (int dir = 0; dir < 4; ++dir)
			{
				int nx = cur.X + dirX[dir];
				int ny = cur.Y + dirY[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				{
					cout << dist[cur.X][cur.Y] + 1 << "\n";
					isEscape = true;
					break;
				}
				if (board[nx][ny] == '#') continue;
				if (dist[nx][ny] != -1) continue;
				if (fire[nx][ny] != -1 && fire[nx][ny] <= dist[cur.X][cur.Y] + 1) continue;

				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				Q2.push({ nx,ny });
			}
		}

		if (!isEscape)
			cout << "IMPOSSIBLE\n";
	}
}