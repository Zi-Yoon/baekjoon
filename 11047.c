#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, k, cnt = 0;
    scanf("%d %d", &n, &k);
    int money[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &money[i]);
 
    for(int i = n - 1; i >= 0; i--)
    {
        if(k - money[i] >= 0)
        {
            k -= money[i];
            cnt++;
            i++;
        }
    }
    printf("%d", cnt);
    return 0;
}