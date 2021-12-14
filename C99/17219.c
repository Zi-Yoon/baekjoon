#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char site[21];
    char pw[21];
} qw;

int compare(const void *a, const void *b)
{
    qw *temp1 = (qw *)a;
    qw *temp2 = (qw *)b;
    return strcmp(temp1->site, temp2->site);
}

int main() {
    int n, m; // 1 ~ 100000 
    scanf("%d %d", &n, &m);
    qw sp[n];
    qw ans[m];
    for (int i = 0;  i < n; i++)
    {
        scanf("%s %s", &sp[i].site, &sp[i].pw);
    }

    qsort(sp,n, sizeof(qw), compare);

    for (int i = 0;  i < m; i++)
    {
        scanf("%s", &ans[i].site);
    }
    qw *temp;
    int cnt = 0;
    char answer[m][21];
    for (int i = 0; i < m;i++)
    {
        if(bsearch(ans[i].site, sp, n, sizeof(qw), compare)!=NULL)
        {
            temp = (int *)bsearch(ans[i].site, sp, n, sizeof(qw), compare);
            strcpy(answer[cnt], temp->pw);
            cnt++;
        }
    }
    for(int i = 0; i < m; i++)
    {
        printf("%s\n", answer[i]);
    }
    return 0;
}