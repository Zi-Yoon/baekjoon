#include <iostream>

using namespace std;

long long a, b, c;

long long div_c(long long a, long long b, long long c)
{
	if (b == 0)
		return 1;

	
	if (b % 2 == 1)
		return ((a % c) * (div_c(a, b - 1, c) % c)) % c;
	else
	{
		long long temp = div_c(a, b / 2, c);
		return ((temp % c) * (temp % c)) % c;
	}
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b >> c;
	cout << div_c(a % c, b, c);
	return 0;
}