#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long ans = 900000000;
long long min;
int n;

typedef struct
{
    int x;
    int y;
    int erased;
} map;

int compare(const void *a, const void *b)
{
    map *temp1 = (map *)a;
    map *temp2 = (map *)b;
    if(temp1->x < temp2->x)
    {
        return -1;
    }
    else if(temp1->x > temp2->x)
    {
        return 1;
    }
    else
    {
        if(temp1->x == temp2->x && temp1->y == temp2->y)
        {
            ans = 0;
            return 0;
        }
        return 0;
    }
}

int compare_i(const void *a, const void *b)
{
    long long num1 = *(long long *)a;
    long long num2 = *(long long *)b;
    if(num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    return 0;
}

long long make_dis(int a, int b, map cdn[]);

int main() 
{
    scanf("%d", &n);
    map cdn[n];
    long long most[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &cdn[i].x, &cdn[i].y);

        // 모두 1사분면으로 이동
        cdn[i].x += 10000;
        cdn[i].y += 10000;
        cdn[i].erased = 0;
    }

    qsort(cdn, n, sizeof(map), compare); // x 오름차순으로 정렬

    if(ans == 0)
    {
        printf("%d", ans);
        return 0;
    }

    long long line = (cdn[n / 2].x + cdn[n / 2 - 1].x) / 2;
    ans = make_dis(0, 1, cdn);

    long long max_d = make_dis(0, 1, cdn);
    most[0] = max_d;

    long long dis = 0;

    for (int i = 1; i < n; i++)
    {
        if(i >= 6){dis = i - 6;}
        while (dis < i)
        {
            int temp = make_dis(i, dis, cdn);
            if(temp <= max_d)
            {
                max_d = temp;
                most[i] = max_d;
                break;
            }
            else
            {
                dis++;
                if(dis == i){dis++;}
            }
        }
    }  

    qsort(most, n-1, sizeof(long long), compare_i);


    printf("%lld", most[0]);
    return 0;
}

long long make_dis(int a, int b, map cdn[])
{   
    int x = cdn[b].x - cdn[a].x;
    int y = cdn[b].y - cdn[a].y;
    long long d = x * x + y * y;
    return d;
}
