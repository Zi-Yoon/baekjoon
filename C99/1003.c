#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int t, n;
    scanf("%d", &t);
    int fb_ans[t];
    int fb_0[41]={1,0,};
    int fb_1[41] = {0,1,};
    for (int i = 2; i <= 40;i++)
    {
        fb_0[i] = fb_0[i - 2] + fb_0[i - 1];
        fb_1[i] = fb_1[i - 2] + fb_1[i - 1];
    }
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        fb_ans[i] = n;
    }
    for (int i = 0; i < t; i++)
    {
        int temp = fb_ans[i];
        printf("%d %d\n",fb_0[temp], fb_1[temp]);
    }
    return 0;
}