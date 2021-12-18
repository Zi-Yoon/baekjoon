#include <iostream>
#include <deque>
#include <string>

using namespace std;

int N;
deque<int> q;
int main(void)
{
	cin >> N;

	int num;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		if (str == "push_front")
		{
			int temp;
			cin >> temp;
			q.push_front(temp);
		}
		else if (str == "push_back")
		{
			int temp;
			cin >> temp;
			q.push_back(temp);
		}
		else if (str == "pop_front")
		{
			if (!q.empty())
			{
				cout << q.front() << "\n";
				q.pop_front();
			}
			else
				cout << "-1\n";
		}
		else if (str == "pop_back")
		{
			if (!q.empty())
			{
				cout << q.back() << "\n";
				q.pop_back();
			}
			else
				cout << "-1\n";
		}
		else if (str == "size")
		{
			cout << q.size() << "\n";
		}
		else if (str == "empty")
		{
			if (q.size() == 0)
				num = 1;
			else
				num = 0;
			cout << num << "\n";
		}
		else if (str == "front")
		{
			if (q.size() == 0)
			{
				num = -1;
			}
			else
			{
				num = q.front();
			}
			cout << num << "\n";
		}
		else if (str == "back")
		{
			if (q.size() == 0)
			{
				num = -1;
			}
			else
			{
				num = q.back();
			}
			cout << num << "\n";
		}
	}
	return 0;
}