#include <stdio.h>
#include <string.h>


int S[21]={0};

int cmp(char a[7])
{
    if((strcmp(a, "add")==0))
    {
        return 1;
    }
    else if((strcmp(a, "remove")==0))
    {
        return 2;
    }
    else if((strcmp(a, "check")==0))
    {
        return 3;
    }
    else if((strcmp(a, "toggle")==0))
    {
        return 4;
    }
    else if((strcmp(a, "all")==0))
    {
        return 5;
    }
    else if((strcmp(a, "empty")==0))
    {
        return 6;
    }
}

int main() {
    int num;
    scanf("%d", &num);
    char order[7] = {0};
    char answer[num];
    int x;
    int y=0;
    int number;
    for (int i = 1; i <= num; i++){
        scanf("%s %d", &order, &x);
        number = cmp(order);
        if (number == 1)
        {
            S[x] = 1;
        }
        else if (number == 2)
        {
            S[x] = 0;
        }
        else if (number == 3)
        {
            if(S[x]==1)
            {
                answer[y]= 1;
            }
            else
            {
                answer[y]= 0;
            }
            y++;
        }
        else if (number == 4)
        {
            int temp;
            if(S[x]==1)
            {
                temp= 0;
            }
            else
            {
                temp= 1;
            }
            S[x] = temp;
        }
        else if (number == 5)
        {
            for (int i = 1; i <= 20; i++)
            {
                S[i] = 1;
            }
        }
        else if (number == 6)
        {
            for (int i = 1; i <= 20; i++)
            {
                S[i] = 0;
            }
        }
    }
    for (int i = 0; i < y; i++)
    {
        printf("%d\n", answer[i]);
    } 
    return 0; 
}
