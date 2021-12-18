#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
string temp[101][101];
int n, m;

string bigint(string num_1, string num_2)
{
	unsigned long long sum = 0;
	string ans;

	while (!num_1.empty() || !num_2.empty() || sum)
	{
		if (!num_1.empty())
		{
			sum += num_1.back() - '0';
			num_1.pop_back();
		}
		if (!num_2.empty())
		{
			sum += num_2.back() - '0';
			num_2.pop_back();
		}
		ans.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

string comb(int n, int m)
{
	if (n == m || m == 0)
		return "1";
	string &result = temp[n][m];
	if (result != "")
		return result;
	result = bigint(comb(n - 1, m - 1), comb(n - 1, m));
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	if(n / 2 < m)
	{
		m = n - m;
	}
	cout << comb(n, m);
	return 0;
}