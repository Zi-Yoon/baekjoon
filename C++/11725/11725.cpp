#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, parent[100001];
bool visit[100001];
vector<int> tree[100001];

void dfs(int num)
{
	visit[num] = true;
	for (int i = 0; i < tree[num].size(); i++)
	{
		int next = tree[num][i];
		if (!visit[next])
		{
			parent[next] = num;
			dfs(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		tree[temp1].push_back(temp2);
		tree[temp2].push_back(temp1);
	}
	dfs(1);
	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << "\n";
	}
	return 0;
}