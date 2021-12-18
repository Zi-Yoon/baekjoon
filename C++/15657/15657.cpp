#include <iostream>
#include <algorithm>
#define MAX 8
using namespace std;

int n, m;
int arr[MAX];
int visit[MAX];

void func(int index, int num, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[visit[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	if (index == n)
	{
		return;
	}
	for (int i = num; i < n; i++)
	{
		visit[index] = i;
		func(index + 1, i, cnt + 1);
	}
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	func(0, 0, 0);
	return 0;
}