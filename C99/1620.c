#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int n, m;
char answer[21];
char temp[21];

typedef struct _dictionary{
    char name[21];
    int num;
} dictionary;

int compare(const void *A, const void *B)
{
    dictionary *ptA = (dictionary *)A;
    dictionary *ptB = (dictionary *)B;

    if (ptA->num < ptB->num) return -1;
    else if (ptA->num > ptB->num) return 1;
    else return 0;
}

int compare_b(const void *a, const void *b)
{
    dictionary *temp1 = (dictionary *)a;
    dictionary *temp2 = (dictionary *)b;
    return strcmp(temp1->name, temp2->name);
}

int main(){
    scanf("%d %d", &n, &m);
    dictionary dic[n];
    dictionary dic2[n];
    int pr_ans_i[m+1];
    char pr_ans_c[m+1][21];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", temp);
        strcpy(dic[i].name, temp);
        strcpy(dic2[i].name, temp);
        dic[i].num = i;
        dic2[i].num = i;
    }

    for (int i = 0; i <= m; i++)
    {
        pr_ans_i[i] = -1;
        for (int j = 0; j < 21; j++)
        {
            pr_ans_c[i][j] = '\0';
        }
    }

    qsort(dic, n, sizeof(dictionary), compare);
    qsort(dic2, n, sizeof(dictionary), compare_b);
    
    for (int j = 0; j < 21; j++)
    {
        answer[j] = '\0';
    }

    for (int i = 0; i < m; i++)
    {

        scanf("%s", answer);

        if(isdigit(answer[0])!=0)
        {
            printf("%s\n", dic[atoi(answer) - 1].name);
        }
        else
        {
            dictionary *pos = (dictionary*) bsearch(answer, dic2->name, n, sizeof(dictionary), compare_b);
            if(pos!=NULL)
            {
                printf("%d\n", pos->num +1);
            }
        }
    }
    return 0;
}