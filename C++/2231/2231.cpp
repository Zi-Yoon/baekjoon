#include <iostream>

using namespace std;

int n, sum, temp;

int main()
{
	cin >> n;
	for (int i = 1; i < n; ++i)
	{
		sum = i;
		temp = i;
		while (temp)
		{
			sum += temp % 10;
			temp /= 10;
		}
		if (n == sum)
		{
			cout << i << "\n";
			return 0;
		}
	}
	cout << "0\n";
	return 0;
}