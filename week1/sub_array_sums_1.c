/*
CSES Problem Set
Subarray Sums I
URL: https://cses.fi/problemset/task/1660
*/



/* 
Approach

    Goal is to check which consecutive items of the array sums up to x

    inital approach - Brut Force :|
        iterate over the array 0-n and take the ith index
            if arr[i] == x 
                increase count 
                continue // skip next loop 
            run another iteration from i to n
                add arr[i] and arr[j] and store to sum
                if sum becomes greater than x 
                    break
                if sum == x
                    increase count
                    break

        This works but Will result in TLE for large data set as in worse case it will run O(n^2) 
        Ex: 200000 100000
            1 1 1 ....... very small numbers
            for each i iteration the j loop will run from start to end - TLE
    

    Aulternate Appraoch:
        In the bruitforce solution the second loop does something interesting
        it adds up each index's value and cehcks if the total sum is greater than x or not
        We can use this:
        H O W?
        
        consecutive n element's sum might be equal to x or might not be
        if we start adding the whole array at some point it should get bigger than x
        if not then answer is 0 , we scanned the whole array no luck
        how ever if we get a bigger value we can assume 2 things 
            1. subtracting 1 or more elements can make the sum equal to x
            2. subtracting 1 or more elements can make the sum less than x
        
        if we ran to case  1:
            we can increase count 
        
        how ever for case 2:
            how can we know which element to subtract 
            clue is in the consecutive word
            that means if we start subtracting from 0 index 
            by each iteration we bring the left pointer forward
            if subtracting the left pointer value makes the sum = x we increase count
            if after subtracting the left pointer value sum > x we increase count and iterate again 
            if after subtracting the left pointer value sum < x we break the iteration 
                - we start adding next indexes again 
            
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x;
    int *arr;

    scanf("%d %d", &n, &x);

    arr = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &arr[i]);
    }

    int count = 0;
    int sum = 0;
    int backlogger = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        while (sum > x)
        {
            sum -= arr[backlogger];
            backlogger++;
        }

        if (sum == x)
        {
            count++;
        }
    }

    printf("%d\n", count);

    free(arr);
    return 0;
}
