#include <iostream>
#include <utility>
using namespace std;

int n, ranking = 1;
pair<int, int> arr[50];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (arr[i].first < arr[j].first &&
				arr[i].second < arr[j].second)
				ranking++;
		cout << ranking << ' ';
		ranking = 1;
	}
	return 0;
}