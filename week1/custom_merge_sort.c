
/* 
I forgot almost every DS and Algorithm
How to regain these knowledges back ?? 

C O D E T H Y S E L F

*/

#include <stdio.h>
#include <stdlib.h>

void merge(int *left_arr, int l_size, int *right_arr, int r_size, int *arr)
{
    
    int left=0,right=0, index=0;
    while (left<l_size && right<r_size)
    {
        if(left_arr[left]<right_arr[right]){
            arr[index]=left_arr[left];
            index++;
            left++;
        }else{
            arr[index]=right_arr[right];
            index++;
            right++;
        }
    }

    if(left<l_size){
        while (left<l_size)
        {
            arr[index]=left_arr[left];
            index++;
            left++;
        }
        
    }
    if(right<r_size){
        while (right<r_size)
        {
            arr[index]=right_arr[right];
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

    int mid = n/2;
    int left[mid];
    int right[n-mid];

    for (int i = 0; i < mid; i++){ left[i]=arr[i]; }
    for (int i = mid; i < n; i++){ right[i-mid]=arr[i]; }
    

    merge_sort(left,mid);
    merge_sort(right, n-mid);

    
    merge(left, mid, right, n-mid, arr);

    return;
}

int main()
{

    int arr[8] = {8, 3, 5, 1, 7, 2, 6, 4};

    merge_sort(arr, 8);

  
    for (int i = 0; i < 8; i++){ printf("%d", arr[i]); }
      printf("\n");

    
}