#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int btree[10001];
int num, m = 0;

void postorder(int a, int b)
{
	// 전위 = root / left / right
	// 후위 = left / right / root
	if (a == b)
		return;
	if (a == b - 1)
	{
		cout << btree[a] << "\n";
		return;
	}
	int index = a + 1;
	while (index < b)
	{
		if(btree[index] < btree[a])
			break;
		index++;
	}
	postorder(a + 1, index);
	postorder(index, b);
	cout << btree[a] << "\n";
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (cin.eof() == 0)
	{
		cin >> btree[m++];
	}
	postorder(0, m);
	return 0;
}