#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int map[1001][1001];
int ans[1001][1001];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m, n;
	cin >> m >> n;
	queue<pair<int, int> > q;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			ans[i][j] = -1;
			if (map[i][j] == 1)
			{
				q.push(make_pair(i, j));
				ans[i][j] = 0;
			}
		}
	}

	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if(map[nx][ny] == 0 && ans[nx][ny] == -1)
				{
					ans[nx][ny] = ans[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	// find max && -1
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			answer = max(answer, ans[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0 && ans[i][j] == -1)
				answer = -1;
		}
	}
	cout << answer;
}