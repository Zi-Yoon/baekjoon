#include <iostream>
#include <algorithm>

using namespace std;

int t, n, arr[4][100003] = {0, }, dp[4][100003] = {0, };

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int k = 1; k <= 2; k++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> arr[k][j];
			}
		}
		// initial inut
		dp[1][1] = arr[1][1];
		dp[2][1] = arr[2][1];
		dp[1][2] = arr[1][2] + dp[2][1];
		dp[2][2] = arr[2][2] + dp[1][1];
		// find first pick
		int y = 1;
		for (int x = 3; x <= n; x++)
		{
			dp[1][x] = arr[1][x] + max(dp[2][x - 1], dp[2][x - 2]);
			dp[2][x] = arr[2][x] + max(dp[1][x - 1], dp[1][x - 2]);
		}
		cout << max(dp[1][n], dp[2][n]) << "\n";
	}
	return 0;
}