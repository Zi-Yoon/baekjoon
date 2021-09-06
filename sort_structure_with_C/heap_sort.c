#include <stdio.h>

void heap_sort(int heap[], int m)
{
    for (int i = 1; i < m; i++)
    {
        int c = i;
        do
        {
            int root = (c - 1) / 2;
            if(heap[root] < heap[c])
            {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
        c = root;
        } while (c != 0);
    }

    for (int i = m - 1; i >= 0; i--)
    {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int c = 1;
        do
        {
            c = 2 * root + 1;
            if(c<i-1 && heap[c] < heap[c+1]){c++;}
            if(c<i && heap[root] < heap[c])
            {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while (c < i);
    }
}

int main(){
    int number = 9;
    int heap[9] = {2, 3, 4, 5, 67, 5, 34, 2, 1};
    heap_sort(heap, number);
}