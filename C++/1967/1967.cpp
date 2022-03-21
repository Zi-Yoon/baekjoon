#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 100001

using namespace std;

int n;
vector<pair<int, int> > v[INF];
int visit[INF] = {0, };
int ans = 0;
int node;

void dfs(int i, int dist)
{
	if (visit[i])
		return;
	if (ans < dist)
	{
		ans = dist;
		node = i;
	}
	visit[i] = 1;
	for (int j = 0; j < v[i].size(); j++)
		dfs(v[i][j].first, v[i][j].second + dist);
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int num, target, cost;
		cin >> num >> target >> cost;
		v[num].push_back(make_pair(target, cost));
		v[target].push_back(make_pair(num, cost));
	}
	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	ans = 0;
	dfs(node, 0);
	cout << ans;
	return 0;
}