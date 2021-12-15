#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int map[501][501];
int visit[501][501];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n, m, ans = 0;

void find_max(int x, int y, int depth, int now)
{
	if (depth == 4)
	{
		if (ans < now)
			ans = now;
		return ;
	}

	// normal shape
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > m || visit[nx][ny])
			continue;
		visit[nx][ny] = 1;
		find_max(nx, ny, depth + 1, now + map[nx][ny]);
		visit[nx][ny] = 0;
	}
	
	// specific shape
	if (x - 1 >= 1 && y - 1 >= 1 && x + 1 <= n)
	{ 
		//ㅓ
		ans = max(ans, (map[x - 1][y] + map[x][y - 1] + map[x][y] + map[x + 1][y]));
	}
	if (x - 1 >= 1 && y + 1 <= m && x + 1 <= n)
	{ 
		//ㅏ
		ans = max(ans, (map[x - 1][y] + map[x][y + 1] + map[x][y] + map[x + 1][y]));
	}
	if (y - 1 >= 1 && y + 1 <= m && x + 1 <= n)
	{ 
		//ㅗ
		ans = max(ans, (map[x][y] + map[x + 1][y] + map[x + 1][y - 1] + map[x + 1][y + 1]));
	}
	if (y - 1 >= 1 && y + 1 <= m && x + 1 <= n)
	{ 
		//ㅜ
		ans = max(ans, (map[x][y - 1] + map[x][y] + map[x][y + 1] + map[x + 1][y]));
	}
}

int main()
{
	// input
	cin >> n >> m;
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			visit[i][j] = 1;
			find_max(i, j, 1, map[i][j]);
			visit[i][j] = 0;
		}
	}
	cout << ans;
	return 0;
}
