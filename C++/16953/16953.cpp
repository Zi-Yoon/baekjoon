#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a, b, ans = 0, cnt = 1;

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> a >> b;

	while (b > a)
	{
		if (b % 2 == 0)
		{
			b = b / 2;
			cnt++;
		}
		else if (b % 10 == 1)
		{
			b = b / 10;
			cnt++;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}
	if (b < a)
	{
		cout << -1;
		return 0;
	}
	cout << cnt;
	return 0;
}