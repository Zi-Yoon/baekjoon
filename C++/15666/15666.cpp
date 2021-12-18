#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define MAX 8
using namespace std;

int n, m;
multiset<int> s;
vector<int> v;
int ans[MAX];
bool visit[MAX];

void func(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visit[i] && v[i] != temp)
		{
			ans[cnt] = v[i];
			temp = ans[cnt];
			visit[i] = true;
			func(cnt + 1);
			visit[i] = false;
		}
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
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	func(0);
	return 0;
}