#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if(num1 < num2)
        return 1;
    if (num1 > num2)
        return -1;
    return 0;
}

int main() {
    int n;
    int ans = 0;
    scanf("%d", &n);
    int time[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &time[i]);
    }
    qsort(time, sizeof(time) / sizeof(int), sizeof(int), compare);

    for (int i = 0; i < n; i++)
    {
        ans += (i+1) * time[i];
    }
    printf("%d", ans);
    return 0;
}
