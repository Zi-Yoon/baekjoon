#include <iostream>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<int>> heap;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int input;
	cin >> n;
	int zero = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input == 0)
			
			if (heap.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << heap.top() << '\n';
				heap.pop();
			}
		else
		{
			heap.push(input);
		}
	}
	return 0;
}