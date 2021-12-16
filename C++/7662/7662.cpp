#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		char input;
		int order;
		multiset<int> heap;
		for (int i = 0; i < n; i++)
		{
			cin >> input >> order;
			if (input == 'I')
			{
				heap.insert(order);
			}
			else
			{
				if (!heap.empty() && order == -1)
				{
					heap.erase(heap.begin());
				}
				else if (!heap.empty() && order == 1)
				{
					auto max = heap.end();
					max--;
					heap.erase(max);
				}
			}
		}
		if (heap.empty())
		{
			cout << "EMPTY" << '\n';
		}
		else
		{
			auto end_max = heap.end();
			end_max--;
			cout << *end_max << ' ' << *heap.begin() << '\n';
		}
	}
	return 0;
}