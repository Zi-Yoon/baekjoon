#include <iostream>
#include <bitset>
#include <cstring>

using namespace std;

int bulb[12][12]; // 원본
int ans = 10000;
int check[12][12];

void push(int k)
{
	int sum = 0;
	int cnt = 0;
	int temp[12][12];
	memmove(temp, check, 12 * 12 * sizeof(int));
	int i = 1, j = 1;
	while (i <= 9)
	{
		j = 1;
		while (j <= 10)
		{
			if (temp[i][j] == 1)
			{
				cnt++;
				temp[i][j] *= -1;		  // 위
				temp[i + 1][j - 1] *= -1; // 왼
				temp[i + 1][j + 1] *= -1; // 오
				temp[i + 1][j] *= -1;	  // 중간
				if (i < 9)
					temp[i + 2][j] *= -1; // 아래
			}
			j++;
		}
		i++;
	}
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			sum += temp[i][j];
	if (sum == -100)
		if (ans > cnt + k)
			ans = cnt + k;
}

// do all possiblity
void first_push()
{
	int count = 0;
	for (int k = 0; k < 1024; k++)
	{
		memmove(check, bulb, 12 * 12 * sizeof(int));
		bitset<10> bits(k);
		count = 0;
		for (int j = 1; j <= 10; j++)
		{
			if (bits[j - 1] == 1)
			{
				check[1][j] *= -1;
				check[1][j - 1] *= -1;
				check[1][j + 1] *= -1;
				check[2][j] *= -1; 
				count++;
			}
		}
		push(count);
	}
}

int main()
{
	int i = 1, j = 1, a = 0;
	char temp_c;
	// make bulb
	memset(bulb, 0, 12 * 12 * sizeof(int));
	while (i <= 10)
	{
		j = 1;
		while (j <= 10)
		{
			cin >> temp_c;
			if (temp_c == '\n')
				j--;
			else if (temp_c == '#')
				bulb[i][j] = -1;
			else if (temp_c == 'O')
				bulb[i][j] = 1;
			j++;
		}
		i++;
	}
	first_push();
	if(ans == 10000)
		cout << -1;
	else
		cout << ans;
	return 0;
}
