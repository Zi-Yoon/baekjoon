#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a;
    int rank;
    int index;
} x;

int compare(const void *a, const void *b)
{
    x *temp1 = (x *)a;
    x *temp2 = (x *)b;
    return (temp1->a - temp2->a);
}

int compare_i(const void *a, const void *b)
{
    x *temp1 = (x *)a;
    x *temp2 = (x *)b;
    return (temp1->index) - (temp2->index);
}

int main() {
    int n;
    scanf("%d", &n);
    x map[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &map[i].a);
        map[i].index = i;
    }
    qsort(map, n, sizeof(x), compare);

    int number = 0;
    for (int i = 0; i < n; i++)
    {
        int j = 1;
        int cnt = 0;
        map[i].rank = number;
        while(map[i].a == map[i+j].a)
        {
            map[i+j].rank = number;
            j++;
            cnt++;
        }
        i += cnt;
        number++;
    }

    qsort(map, n, sizeof(x), compare_i);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", map[i].rank);
    }
    return 0;
}
