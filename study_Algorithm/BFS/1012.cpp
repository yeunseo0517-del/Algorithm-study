//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

int bfs[51][51];
bool vis[51][51];

#define X first
#define Y second

int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n, m, k;
		int num = 0;

		cin >> m >> n >> k;

		while (k--)
		{
			int x, y;
			cin >> x >> y;
			bfs[y][x] = 1;
		}
		
		for(int i=0;i<n;++i)
			for (int j = 0; j < m; ++j)
			{
				if (bfs[i][j] == 0 || vis[i][j]) continue;
				
				num++;
				queue<pair<int, int>> Q;
				
				Q.push({ i, j });
				vis[i][j] = true;

				while (!Q.empty())
				{
					pair<int, int> cur = Q.front();	Q.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int nx = cur.X + dirX[dir];
 						int ny = cur.Y + dirY[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;
						if (bfs[nx][ny] == 0 || vis[nx][ny]) continue;

						vis[nx][ny] = true;
						Q.push({ nx,ny });
					}
				}
			}

		cout << num << "\n";
		for (int i = 0; i < n; ++i)
		{
			fill(bfs[i], bfs[i] + m, 0);
			fill(vis[i], vis[i] + m, false);
		}
	}
}