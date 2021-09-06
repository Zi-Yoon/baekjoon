#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compare(const void *a, const void *b)
{
    return strcmp((char*)a, (char*)b);
}

int main() {
    char *word = (char*)malloc(sizeof(char) * 1000001);
    char count[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%s", word);
    int len = strlen(word);
    int count_num[27] = {0,};
    for (int i = 0; i < len; i++)
    {
        word[i]=toupper(word[i]);
    }

    int cnt = 0;

    for (int i = 0; i < 27; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if(word[j] == count[i])
            {
                count_num[i]++;
            }
        }
    }

    int max = 0;
    // find max
    for (int k = 0; k < 27;k++)
    {
        if (count_num[k] > max)
        {
            max = count_num[k];
        }
    }

    // find max char
    for (int m = 0; m < 27; m++)
    {
        if (count_num[m] == max)
        {
            cnt++;
        }
    }

    // last
    if (cnt >= 2){

        printf("?");
        
        return 0;
    }
    else
    {
        for (int i = 0; i < 27; i++)
        {
            if(count_num[i] == max)
            {
                printf("%c",count[i]);
                free(word);
                return 0;
            }
        }
    }

}
