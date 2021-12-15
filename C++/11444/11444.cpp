#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
long long target;
map<long long, long long> ans;
long long mod = 1000000007;

long long fibonachi(long long n)
{
	if (n <= 0)
		return 0;
	else if (n == 1)
	{
		ans[1] = 1;
		return 1;
	}
	else if (n == 2)
	{
		ans[2] = 1;
		return 1;
	}
	else if (ans.count(n) > 0)
		return ans[n];
	else
	{
		if (n % 2 == 0)
		{
			// 1 1 2 3 5 8 13 21
			long long a = fibonachi(n / 2 - 1);
			long long b = fibonachi(n / 2);
			// long long c = fibonachi(n / 2 + 1);
			// ans[n] = ab*bc = b(a+c) = b(a+a+b) = b(2a+b) = 2ab+b^2
			ans[n] = (2 * a + b) % mod * b % mod;
			return ans[n];
		}
		else
		{
			long long a = fibonachi(n / 2 + 1);
			long long b = fibonachi(n / 2);
			ans[n] = (a * a) % mod + (b * b) % mod;
			return ans[n];
		}
	}
}

int main()
{
	cin >> target;
	cout << fibonachi(target) % mod;
	return 0;
}
