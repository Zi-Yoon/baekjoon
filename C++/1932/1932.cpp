#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, mnum = 0;
int arr[501][501];
int dp[501][501] = {0, };

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			cin >> arr[i][j];
	}

	// 초기값 넣기
	dp[1][1] = arr[1][1];

	// 큰수 고르기
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
	}

	// max 찾기
	for (int i = 1; i <= n; i++)
	{
		if (mnum < dp[n][i])
			mnum = dp[n][i];
	}
	cout << mnum << "\n";
	return 0;
}