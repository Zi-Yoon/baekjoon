#include <iostream>
#include <vector>
#include <queue>
#define MAX 20010
#define INF 987654321
using namespace std;

int v, e, start;
int dist[MAX];
vector<pair<int, int> > map[MAX];

void Input()
{
	cin >> v >> e >> start;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= v; i++)
	{
		dist[i] = INF;
	}
}

void Dijkstra()
{
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < map[cur].size(); i++)
		{
			int next = map[cur][i].first;
			int ncost = map[cur][i].second;

			if (dist[next] > cost + ncost)
			{
				dist[next] = cost + ncost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}
	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Input();
	Dijkstra();
	return 0;
}