#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
int dp[100001] = {99999999, };
queue<int> Q;

void bfs()
{
	int temp;
	Q.push(n);
	dp[n] = 0;
	while (!Q.empty())
	{
		temp = Q.front();
		Q.pop();
		if (temp == k)
			return;
		if (temp + 1 < 100001 && dp[temp + 1] > dp[temp] + 1)
		{
			dp[temp + 1] = dp[temp] + 1;
			Q.push(temp + 1);
		}
		if (temp - 1 >= 0 && dp[temp - 1] > dp[temp] + 1)
		{
			dp[temp - 1] = dp[temp] + 1;
			Q.push(temp - 1);
		}
		if (temp * 2 < 100001 && dp[temp * 2] > dp[temp])
		{
			dp[temp * 2] = dp[temp];
			Q.push(temp * 2);
		}
	}
}
int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < 100001; i++)
	{
		dp[i] = 99999999;
	}
	bfs();
	cout << dp[k];
}