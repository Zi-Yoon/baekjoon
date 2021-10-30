#include <stdio.h>
#include <stdlib.h>

int three = 4;
int two = 2;
int one = 1;

int cnt(int n)
{
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else if (n == 3) return 4;
	else return cnt(n - 1) + cnt(n - 2) + cnt(n - 3);
}

int main() {
    int t;
    scanf("%d", &t);
    int a;
    int ans[t];
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &a);
        ans[i] = cnt(a);
    }
    for (int i = 0; i < t; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}