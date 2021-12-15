#include <iostream>

using namespace std;

int main()
{
	int n;
	int m[1000] = {};
	int re[1000] = {};
	int max = 0;
	double sum = 0, ans;

	cin >> n;

	// find max
	for (int i = 0; i < n; i++)
	{
		cin >> m[i];
		if (m[i] > max)
			max = m[i];
		sum += m[i];
	}

	// make new score -> make new ans
	ans = (sum / max * 100) / n;

	// fixed 사용법 
	cout << fixed;
	cout.precision(6);
	cout << ans << endl;
	return 0;
}