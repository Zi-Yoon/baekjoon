#include <iostream>
#include <cmath>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX] = {
	0,
};
bool visit[MAX] = {
	false,
};

void dfs(int num, int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; i++)
	{
		visit[i] = true;
		arr[depth] = i;
		dfs(i, depth + 1);
		visit[i] = false;
	}
}

int main()
{
	cin >> n >> m;
	dfs(1, 0);
	return 0;
}