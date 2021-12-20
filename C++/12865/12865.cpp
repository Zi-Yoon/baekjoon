#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int weight[102];
int value[102];
int dp[102][100002];


void get_ans()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j >= weight[i])
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][k] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> weight[i] >> value[i];
	}
	get_ans();
	return 0;
}
