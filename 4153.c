#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a, b, c;
    int cnt = 0;
    int check[100000] = {0,};
    while(1)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(c>a && c>b)
        {
            if (pow(c,2) == pow(a,2) + pow(b,2))
            {
                check[cnt] = 1;
            }
            else
                check[cnt] = 2;
        }
        else if(b>a && b>c)
        {
            if (pow(b,2) == pow(a,2) + pow(c,2))
            {
                check[cnt] = 1;
            }
            else
                check[cnt] = 2;
        }
        else if(a>b && a>c)
        {
            if (pow(a,2) == pow(b,2) + pow(c,2))
            {
                check[cnt] = 1;
            }
            else
                check[cnt] = 2;
        }
        else if(a==b==c==0)
        {
            break;
        }
        cnt++;
    }
    for (int i = 0; i < cnt+2; i++){
        if(check[i]==1){
            printf("right\n");
        }
        else if(check[i]==2){
            printf("wrong\n");
        }
        else{
            return 0;
        }
    }
}