#include <iostream>
#include <algorithm>

using namespace std;

int n, ans, dp[1001], arr[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if(arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}

