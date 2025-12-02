/*
CSES Problem Set
Distinct Numbers
URL: https://cses.fi/problemset/task/1621/
*/


/* 
Approach: 
    if the list is sorted i can check 
    if current numer is equal to next number ? 
     if yes skip
     if no then these 2 no are diff - so increase count
    
    why this works? 
     Made the list sorted    
    
    sorting algorith used:
     merged sort
    
    Why merge sort? 
     best, avg, worst O(n logn)
     also range was 10^9 = 1000000000 A bit large :)

*/
#include <stdio.h>
#include <stdlib.h>

void merge(int *left_arr, int l_size, int *right_arr, int r_size, int *arr)
{

    int left = 0, right = 0, index = 0;
    while (left < l_size && right < r_size)
    {
        if (left_arr[left] < right_arr[right])
        {
            arr[index] = left_arr[left];
            index++;
            left++;
        }
        else
        {
            arr[index] = right_arr[right];
            index++;
            right++;
        }
    }

    if (left < l_size)
    {
        while (left < l_size)
        {
            arr[index] = left_arr[left];
            index++;
            left++;
        }
    }
    if (right < r_size)
    {
        while (right < r_size)
        {
            arr[index] = right_arr[right];
            index++;
            right++;
        }
    }
}

void merge_sort(int *arr, int n)
{

    if (n <= 1)
    {
        return;
    }

    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++)
    {
        right[i - mid] = arr[i];
    }

    merge_sort(left, mid);
    merge_sort(right, n - mid);

    merge(left, mid, right, n - mid, arr);

    return;
}

int main()
{

    int n;
    int *arr;

    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &arr[i]);
    }

    merge_sort(arr, n);


    int count = 1;
    int current_num = arr[0];
    for (int i = 0; i < n; i++)
    {
       if(arr[i]!=current_num){
        count++;
        current_num=arr[i];
       }
    }

    printf("%d\n", count);
    free(arr);
    return 0;
}