#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int n, temp;

typedef struct stack
{
	char data;
	struct stack* link;
}stack;

stack *top;

int is_empty()
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}

void push(char data)
{
    stack *newnode = (stack *)malloc(sizeof(stack));
    newnode->data = data;
    newnode->link = top;
    top = newnode;
}

char pop()
{
    if(!is_empty()) 
    {
        stack *temp = top;
        char data = temp->data;
        top = temp->link;
        free(temp);
        return data;
    }
    else
        return -1;
}

int main() 
{
    char order[52];
    scanf("%d", &n);
    stack *s = NULL;
    for (int i = 0; i < n; i++)
    {    
        //reset
        for (int i = 0; i < 50; i++)
        {
            order[i] = '0';
        }
    
        int cnt = 0;
        int end = 0;

        scanf("%s", &order);

        for (int i = 0; i < 50; i++)
        {
            if(order[i] =='(')
            {
                push('(');
                cnt++;
            }
            else if(order[i] ==')')
            {
                char temp1 = pop();
                if(temp1 != '(')
                {
                    end++;
                }
                else if(temp1 == '(')
                {
                    cnt--;
                }
            }
            else
            {
                break;
            }
        }

        if (cnt == 0 && end == 0 && !is_empty())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}