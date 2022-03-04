#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 999999999

using namespace std;

int v, e, k; // 정점, 간선, 시작정점번호
int dist[30000];
vector<pair<int, int> > map[30000];

void input()
{
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= v; i++)
	{
		dist[i] = MAX;
	}
}

// 힙구조
// 가까운 순서대로 처리 = 큐를 사용
// 짧은 것이 먼저 오도록 음수화를 함
// 최단 거리가 아닌경우 스킵
// 선택된 노드의 인접노드 = next
// 선택된 노드를 인접 노드로 거쳐서 가는 비용 = nextDistance
// 기존의 최소 비용보다 더 저렴하면 둘을 교체
void dijkstra()
{
	priority_queue<pair<int, int> > pr_que;
	pr_que.push(make_pair(0, k));
	dist[k] = 0;
	while (!pr_que.empty())
	{
		int cost = -pr_que.top().first;
		int cur = pr_que.top().second;
		pr_que.pop();
		for (int i = 0; i < map[cur].size(); i++)
		{
			int next = map[cur][i].first;
			int n_cost = map[cur][i].second;
			if (dist[next] > cost + n_cost)
			{
				dist[next] = cost + n_cost;
				pr_que.push(make_pair(-dist[next], next));
			}
		}
	}
	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == MAX)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> v >> e >> k;
	input();
	dijkstra();
	return 0;
}