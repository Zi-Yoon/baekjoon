#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n; //MAX 50000
    scanf("%d", &n);
    int temp = sqrt(n);
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int sqa, sqb, sqc, sqd;
    for (d = 0; d <= temp; d++)
    {
        for (c = 0; c <= temp; c++)
        {
            for (b = 0; b <= temp; b++)
            {
                for (a = 0; a <= temp; a++)
                {
                    sqa = pow(a, 2);
                    sqb = pow(b, 2);
                    sqc = pow(c, 2);
                    sqd = pow(d, 2);
                    if(sqa+sqb+sqc+sqd == n)
                    {
                        if (d==0){if(c==0){if(b==0){printf("%d",1);}else{printf("%d",2);}}else{printf("%d",3);}}else{printf("%d",4);}
                        return 0;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
    }
}