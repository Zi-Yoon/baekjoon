#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 9, k;
vector<int> v1;
vector<int> v2;

int main()
{
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v1.push_back(temp);
		v2.push_back(temp);
	}
	sort(v1.begin(),v1.end());
	cout << v1[8] << "\n";
	auto num = find(v2.begin(), v2.end(), v1[8]);
	cout << num - v2.begin() + 1;
	return 0;
}