#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n;
	vector<int> vec(n);
	// input & sort
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	
	// do mapping
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		auto up = upper_bound(vec.begin(), vec.end(), temp);
		auto low = lower_bound(vec.begin(), vec.end(), temp);
		cout << up - low << " ";
	}
	cout << endl;
	return 0;
}
