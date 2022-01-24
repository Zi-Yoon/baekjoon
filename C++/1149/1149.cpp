#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, answer = 0;
int arr[3][1001] = {0, };
int dp[3][1001] = {0, };

int small(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	else if (b <= a && b <= c)
		return b;
	return c;
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
	dp[0][0] = arr[0][0]; // select R
	dp[1][0] = arr[1][0]; // select G
	dp[2][0] = arr[2][0]; // select B
	for (int i = 1; i < n; i++)
	{
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + arr[0][i];
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + arr[1][i];
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + arr[2][i];
	}
	answer = small(dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]);
	cout << answer;
	return 0;
}