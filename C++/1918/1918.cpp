#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

string s;
stack<char> repo;

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			cout << s[i];
		}
		else
		{
			if (s[i] == '(')
				repo.push(s[i]);
			else if (s[i] == '*' || s[i] =='/')
			{
				while (!repo.empty() && (repo.top() == '*' || repo.top() =='/'))
				{
					cout << repo.top();
					repo.pop();
				}
				repo.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				while (!repo.empty() && repo.top() != '(')
				{
					cout << repo.top();
					repo.pop();
				}
				repo.push(s[i]);
			}
			else if (s[i] == ')')
			{
				while (!repo.empty() && repo.top() != '(')
				{
					cout << repo.top();
					repo.pop();
				}
				repo.pop();
			}
		}
	}
	while (!repo.empty())
	{
		cout << repo.top();
		repo.pop();
	}
	return 0;
}