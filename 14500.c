#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m; // 4 <= N, M <= 500
int ans = 0;
int map[502][502]; // (1, 1)부터 시작
int track[502][502];
int max = 0;

void find_next(int i, int j, int k);
void re(int a, int b, int c);
void find_next_2(int i, int j);

int main()
{
	int i = 1, j = 1, k = 0;
	memset(map, 0, 502 * 502 * sizeof(int));
	scanf("%d %d", &n, &m);
	while(n >= i)
	{
		j = 1;
		while (m >= j)
		{
			scanf("%d", &k);
			map[i][j] = k;
			j++;
		}
		i++;
	}
	i = n - 1;
	j = m - 1;
	while (i > 1)
	{
		j = m - 1;
		while (j > 1)
		{
			memset(track, 0, (n + 1) * (m + 1) * sizeof(int));
			find_next(i, j, 0);
			find_next_2(i, j);
			j--;
		}
		i--;
	}
	printf("%d", ans);
	return 0;
}

void re(int a, int b, int c)
{
	find_next(a, b, c);
	max -= map[a][b];
}

void find_next(int i, int j, int k)
{
	if (i <= 0 || j <= 0 || i > n || j > m)
		return;
	max += map[i][j];
	track[i][j] = 1;
	if (k == 3)
	{
		track[i][j] = 0;
		if (max > ans)
			ans = max;
		return;
	}
	if (track[i + 1][j] == 0)
		re(i + 1, j, k + 1);
	if (track[i][j + 1] == 0)
		re(i, j + 1, k + 1);
	if (track[i - 1][j] == 0)
		re(i - 1, j, k + 1);
	if (track[i][j - 1] == 0)
		re(i, j - 1, k + 1);
	track[i][j] = 0;
	return;
}

void find_next_2(int i, int j)
{
	int maxxx = 0;
	maxxx += map[i][j];
	maxxx += map[i + 1][j];
	maxxx += map[i][j + 1];
	maxxx += map[i - 1][j];
	maxxx += map[i][j - 1];
	max = maxxx - map[i + 1][j];
	if (max > ans)
		ans = max;
	max = maxxx - map[i][j + 1];
	if (max > ans)
		ans = max;
	max = maxxx - map[i - 1][j];
	if (max > ans)
		ans = max;
	max = maxxx - map[i][j - 1];
	if (max > ans)
		ans = max;
	max = 0;
	return;
}
