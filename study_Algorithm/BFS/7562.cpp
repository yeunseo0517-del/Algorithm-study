#include <bits/stdc++.h>
using namespace std;

int dist[304][304];

#define X first
#define Y second

int dirX[8] = { -2,-2,-1,-1,1,1,2,2 };
int dirY[8] = { -1,1,-2,2,-2,2,-1,1 };

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;

	cin >> t;

	while (t--)
	{
		int n, fromX, fromY, toX, toY;
		cin >> n >> fromX >> fromY >> toX >> toY;

		for (int i = 0; i < n; ++i)
			fill(dist[i], dist[i] + n, -1);

		queue<pair<int, int>> Q;
		dist[fromX][fromY] = 0;
		Q.push({ fromX,fromY });

		while (dist[toX][toY] == -1)
		{
			pair<int, int> cur = Q.front(); Q.pop();

			for (int dir = 0; dir < 8; ++dir)
			{
				int nx = cur.X + dirX[dir];
				int ny = cur.Y + dirY[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (dist[nx][ny] != -1) continue;

				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				Q.push({ nx,ny });
			}
		}

		cout << dist[toX][toY] << "\n";
	}
}