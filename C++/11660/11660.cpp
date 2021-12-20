#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int arr[1050][1050] = {0, };
int dp[1050][1050] = {0, };
int x1, y1, x2, y2;

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int temp;
			cin >> temp;
			arr[i][j] = temp;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
	}
	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		sum = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 -1][y1 - 1];
		cout << sum << "\n";
	}
	return 0;
}