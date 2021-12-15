#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char c;
	int n;
	int cnt_eol = 0;
	cin >> n;

	int arr[1000][50] = {};
	for (int i = 0; i < n; i++)
	{
		memset(arr[i], 0, sizeof(int) * 50);
	}
	int k = 0;
	c = cin.get();
	while(cnt_eol < n)
	{
		c = cin.get();
		if (c == '\0')
			break;
		if (c == '(')
			arr[cnt_eol][k] = 1;
		else if (c == ')')
			arr[cnt_eol][k] = -1;
		else if (c == '\n')
		{
			arr[cnt_eol][k] = 0;
			cnt_eol++;
			k = -1;
		}
		k++;
	}
	for (int i = 0; i < n; i++)
	{
		int j = 0, l = 0;
		int check = 0;
		while (j < 50)
		{
			if (check < 0)
			{
				l++;
				cout << "NO" << endl;
				break;
			}
			check += arr[i][j];
			j++;
		}
		if (j == 50 && check == 0)
		{
			cout << "YES" << endl;
		}
		else if (j == 50 && check > 0)
		{
			cout << "NO" << endl;
		}
		l = 0;
	}
	return 0;
}