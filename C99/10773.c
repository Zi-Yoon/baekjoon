#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, temp;
int order;

typedef struct stack
{
	int data;
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

void push(int data)
{
    stack *newnode = (stack *)malloc(sizeof(stack));
    newnode->data = data;
    newnode->link = top;
    top = newnode;
}

int pop()
{
    stack *temp = top;
    int data = temp->data;
    top = temp->link;
    free(temp);
    return data;
}

int sum()
{
    int ans = 0;
    while(!is_empty())
    {
        ans += pop();
    }
    return ans;
}

int main() 
{
    scanf("%d", &n);
    stack *s = NULL;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &order);
        if(order!=0)
        {
            push(order);
        }
        else if(order == 0)
        {
            pop();
            cnt++;
        }
    }
    printf("%d", sum());
    return 0;
}