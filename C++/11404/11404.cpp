#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, m;
int dp[101][101];

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n ; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		dp[start][end] = min(dp[start][end], cost);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] == INF)
			{
				cout << 0 << ' ';
				continue;
			}
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}