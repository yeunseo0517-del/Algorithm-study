//#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <queue>

int bfs[1002][1002];
int date[1002][1002];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

#define X first
#define Y second

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n, finalDate = 0, now = 0;

	cin >> m >> n;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> bfs[i][j];

	queue<pair<int, int>> Q;

	for(int i=0;i<n;++i)
		for (int j = 0; j < m; ++j)
		{
			if (bfs[i][j] != 0) continue;

			Q.push({ i,j });

			while (!Q.empty())
			{
				pair<int, int> cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; ++dir)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (bfs[nx][ny] == -1) continue;

					if (bfs[nx][ny] == 0)
						now = ;
					Q.push({ nx,ny });
				}
			}
			//finalDate = (finalDate > )
		}

	cout << now;
}