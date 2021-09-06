# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int compare(const void *a, const void *b)
{
    char str1 = *(char *)a;
    char str2 = *(char *)b;
    return strcmp(a, b);
}


int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char listen[n][21];
    char see[m][21];
    char both[m][21];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &listen[i]);
    }
    qsort(listen, n, 21, compare);
    for (int i = 0; i < m; i++)
    {
        scanf("%s", &see[i]);
    }
    qsort(see, m, 21, compare);
    for (int i = 0; i < m; i++)
    {
        if(bsearch(see[i], listen, n, sizeof(listen[0]), compare)!=NULL)
        {
            cnt++;
            strcpy(both[cnt-1], see[i]);
        }
    }
    printf("%d\n", cnt);
    qsort(both, cnt, 21, compare);
    for (int i = 0; i < cnt; i++)
    {
        printf("%s\n", both[i]);
    }
    return 0;
}