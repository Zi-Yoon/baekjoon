#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main() {
    long num, meter;
    scanf("%ld %ld", &num, &meter);
    long tree[num];
    for (long i = 0; i < num; i++)
    {
        scanf("%ld", &tree[i]);
    }
    long high = 0;
    long take = 0;
    long max = 0;

    // find max
    qsort(tree, sizeof(tree)/sizeof(long), sizeof(long), compare);

    max = tree[0];

    // max 부터 차례대로 내려가면서 cut
    for (long j = max; j >0 ; j--)
    {
        take = 0;
        for (long i = 0; i < num; i++)
        {
            if ((tree[i] - j) > 0)
            {
                take += tree[i] - j;
            }
            else if((tree[i] - j) <= 0)
            {
                break;
            }
            if (take >= meter)
            {
                printf("%ld", j);
                return 0;
            }
        }
    }
}