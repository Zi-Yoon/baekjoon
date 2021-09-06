#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Bulb[10];
char temp[1];

void On_Off(int x, int y)
{

}

int

int main() 
{
    memset(Bulb, 0, sizeof(Bulb));
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 9; j >= 0; j--)
        {
            scanf("%c", temp);
            if(temp[0] == '\n')
            {
                j++;
                continue;
            }
            if(temp[0] == 'O')
            {
                Bulb[i] += pow(2, j);
            }
        }
    }
    for (int i = 0; i <= 9; i++)
    {
        if(Bulb[i]!=0)
        {
            for (int j = 9; j >= 0; j--)
            {

            }
        }
    



}