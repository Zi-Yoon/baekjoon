#include <stdio.h>

int number = 8;
int sorted[8];

void merge(int a[], int m, int middle, int n) // start middle end
{
    int i = m;
    int j = middle + 1;
    int k = 0;
    while(i <= middle && j <= n)
    {
        if(a[i] <= a[j])
        {
            sorted[k] = a[i];
            i++;
        }
        else
        {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    if(i > middle){
        for (int t = j; t <= n; t++)
        {
            sorted[k] = a[t];
            k++;
        }
    }
    else{
        for (int t = i; t <= n; t++)
        {
            sorted[k] = a[t];
            k++;
        }
    }
    for (int t = m; t <= n; t++)
    {
        a[t] = sorted[t];
    }
}

void sort_merge(int a[], int m, int n)
{
    if(m<n)
    {
        int middle = (m + n) / 2;
        sort_merge(a, m, middle);
        sort_merge(a, middle + 1, n);
        merge(a, m, middle, n);
    }
}

int main() {
    int arr[8] = {7,8,9,6,4,4,7,8};
    sort_merge(arr, 0, number - 1);
    return 0;
}