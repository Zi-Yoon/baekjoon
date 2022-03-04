#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string n, m;
int dp[1002][1002] = {0, };

void find_lcs()
{
	int i, j;
	for (i = 1; i <= n.length(); i++)
	{
		for (j = 1; j <= m.length(); j++)
		{
			if (n[i - 1] == m[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	cout << dp[n.length()][m.length()] << "\n";
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	find_lcs();
	return 0;
}

