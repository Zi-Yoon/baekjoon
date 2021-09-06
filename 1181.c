#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int over = 0;

int compare(const void *a, const void *b)
{
    if (strlen((char*)a) > strlen((char*)b)) return 1;
    else if (strlen((char*)a) < strlen((char*)b)) return -1;
    else 
    {
        if(strcmp((char*)a, (char*)b)==0){over++;}
        return strcmp((char*)a, (char*)b);
    }
}

int main() 
{
	// 변수 선언
	int num;
    char temp1[51];
    char null_temp[51] = {"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"};
    int over = 0;
    // 입력
	scanf("%d", &num);
	char word[num][51];
    
	for (int i = 0; i < num; i++)
    {
		scanf("%s", word[i]);
    }

    if(num == 1)
    {
        printf("%s", word[0]);
        return 0;
    }

    // 길이순 + 사전순
    qsort(word, num, sizeof(word[0]), compare);

    // 중복 제거
    for (int i = 0; i < num-1; i++)
    {
        int k = 1;
        while (strcmp(word[i], word[i+k]) == 0)
        {
            strcpy(word[i+k], null_temp);
            k++;
            if (i + k >= num-1)
            {
                break;
            }
        }
        if (i + k >= num-1)
        {
            break;
        }
    }

    qsort(word, num, sizeof(word[0]), compare);

    for (int i = num; i > 0; i--)
    {
        if(strcmp(word[i], null_temp)){
            over++;
        }
    }

    for (int i = 0; i < num-over; i++)
    {
		printf("%s\n", word[i]);
	}
	return 0;
}