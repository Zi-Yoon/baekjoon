#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define INF 100001
using namespace std;

int tc, n, m, w;
int dist[510];
string ans;
vector<pair<pair<int, int>, int> > v;

void bellman_ford()
{
	// Calculated node
	dist[1] = 0;
	// check less-cost for all node
	// at least need (n - 1) check for find it
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			int a = v[j].first.first;
			int b = v[j].first.second;
			int cost = v[j].second;
			if (dist[a] == INF)
				continue;
			if (dist[b] > dist[a] + cost)
				dist[b] = dist[a] + cost;
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		int a = v[i].first.first;
		int b = v[i].first.second;
		int cost = v[i].second;

		if (dist[a] == INF)
			continue;
		if (dist[b] > dist[a] + cost)
		{
			ans = "YES";
			return;
		}
	}
	ans = "NO";
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		// clear
		for (int i = 1; i < 510; i++)
			dist[i] = INF;
		memset(dist, -1, sizeof(dist));
		v.clear();

		// input
		cin >> n >> m >> w;
		int a, b, cost;
		for (int j = 0; j < m; j++)
		{
			// 양수
			int a, b, cost;
			cin >> a >> b >> cost;
			v.push_back(make_pair(make_pair(a, b), cost));
			v.push_back(make_pair(make_pair(b, a), cost));
		}
		for (int j = 0; j < w; j++)
		{
			// 음수
			int a, b, cost;
			cin >> a >> b >> cost;
			v.push_back(make_pair(make_pair(a, b), -cost));
		}
		// solve start
		bellman_ford();
		cout << ans << '\n';
	}
	return 0;
}

