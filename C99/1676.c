#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    unsigned long long factorial = 1;
    int cnt = 0;
    for (int i = 1; i <= num;i++)
    {
        factorial = factorial * i;
        while(factorial % 10 == 0)
        {
            factorial = factorial / 10;
            cnt++;
        }
        unsigned long long temp = factorial;
        temp = temp / 1000;
        temp = temp * 1000;
        factorial = factorial - temp;
    }
    printf("%d", cnt);
    return 0;
}