#include <iostream>
#include <queue>

using namespace std;
int n, m;
bool visit[300000] = {false, };
int t[300000] = {0, };

void bfs(int x)
{
	queue<int>q;
	q.push(x);
	while(!q.empty())
	{
		int now = q.front();
		visit[now] = true;
		if (visit[m] == true)
			break;
		q.pop();
		if (0 <= now - 1)
		{
			if (!visit[now - 1])
			{
				visit[now - 1] = true;
				q.push(now - 1);
				t[now - 1] = t[now] + 1;
			}
		}
		if (now + 1 <= 2 * m)
		{
			if (!visit[now + 1])
			{
				visit[now + 1] = true;
				q.push(now + 1);
				t[now + 1] = t[now] + 1;
			}
		}
		if (0 <= 2 * now && 2 * now <= 2 * m)
		{
			if (!visit[2 * now])
			{
				visit[2 * now] = true;
				q.push(2 * now);
				t[2 * now] = t[now] + 1;
			}
		}
	}
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	bfs(n);
	cout << t[m];
}