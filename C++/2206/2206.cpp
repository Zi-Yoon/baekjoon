#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define endl "\n"
#define MAX 1000
using namespace std;

int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX][2];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int bfs()
{
	// 4개를 하나의 큐에 대입
	queue<pair<pair<int, int>, pair<int,int> > > q;
    q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	visit[0][0][0] = 1;

	while (!q.empty())
	{
		// x, y 좌표
		// b는 벽 부순 횟수
		// cnt는 현재 칸수
		int x = q.front().first.first;
		int y = q.front().first.second;
		int b = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		
		if (x == n - 1 && y == m - 1)
			return cnt;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				// 벽 뚫은 횟수 0이고 벽이 막혀 있을 때
				if (map[nx][ny] == 1 && b == 0)
				{
					visit[nx][ny][b + 1] = 1;
					q.push(make_pair(make_pair(nx, ny), make_pair(b + 1, cnt + 1)));
				}
				// 가려는 곳을 방문하지 않았고(지나온 경로가 아니고) 안막혀있을때
				else if (map[nx][ny] == 0 && visit[nx][ny][b] == 0)
				{
					visit[nx][ny][b] = 1;
					q.push(make_pair(make_pair(nx, ny), make_pair(b, cnt + 1)));
				}
			}
		}
	}
	return -1;
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            int temp = s[j] - '0';
            map[i][j] = temp;
        }
    }
	cout << bfs() << endl;
	return 0;
}