#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m;
int arr[1002][1002];
int ans = 0, cnt_zero = 0, cnt_one = 0, check = 0, check_one = 0;

typedef struct one_map{
	int x;
	int y;
} One_map;

One_map xy[1000000];

void bfs(int x, int y)
{
	arr[x][y]++;
	arr[x + 1][y]++;
	arr[x - 1][y]++;
	arr[x][y + 1]++;
	arr[x][y - 1]++;
}

void find_one(int cnt)
{
	int i = 0;
	while (cnt > i)
	{
		bfs(xy[i].x, xy[i].y);
		i++;
	}
}

int check_zero()
{
	int i = 1, j = 1;
	check = 0;
	check_one = 0;
	while (j <= m)
	{
		i = 1;
		while (i <= n)
		{
			if (arr[j][i] > 0)
			{
				if (arr[j][i] >= 1)
				{
					xy[check].x = j;
					xy[check].y = i;
					check_one++;
				}
			}
			else
				check++;
			i++;
		}
		j++;
	}
	if (check == 0)
		return 1;
	else
		return 0;
}

int main()
{
	
	scanf("%d %d", &n, &m); // 1000 이하
	memset(arr, 0, 1002 * 1002 * sizeof(int));
	int i = 1, j = 1, k = 0;
	while (j <= m)
	{
		i = 1;
		while (i <= n)
		{
			scanf("%d", &k);
			if (k == 0)
			{
				arr[j][i] = 0;
				cnt_zero++;
			}
			else if (k == 1)
			{
				xy[cnt_one].x = j;
				xy[cnt_one].y = i;
				arr[j][i] = 1;
				cnt_one++;
			}
			else if (k == -1)
				arr[j][i] = -10000;
			i++;
		}
		j++;
	}
	if (cnt_zero == 0)
	{
		printf("%d", 0);
		return 0;
	}
	find_one(cnt_one);
	ans++;
	while (check_zero() == 0)
	{
		find_one(check_one);
		ans++;
		if(ans > 1000000)
		{
			printf("%d", -1);
			return 0;
		}
	}
	printf("%d", ans);
	return 0;
}
