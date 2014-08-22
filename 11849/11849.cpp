#include <stdio.h>

int array[1000000];
 
int binary_search(int a[], int low, int high, int target) 
{
    while (low <= high) 
    {
        int middle = low + (high - low)/2;
        if (target < a[middle])
            high = middle - 1;
        else if (target > a[middle])
            low = middle + 1;
        else
            return middle;
    }
    return -1;
}

int main()
{
    int a = 1, b = 1;
    freopen("11849.INP","r",stdin);
    freopen("11849.OUT","w",stdout);
    scanf("%d %d", &a, &b);
    while(a != 0 && b != 0)
    {
        int count = 0;
        int i = 0;
        for(i = 0; i < a; ++i)
        {
            int temp;
            scanf("%d", &temp);
            array[i] = temp;
        }
              
        for(i = 0; i < b; ++i)
        {
            int temp;
            scanf("%d", &temp);
            int found = binary_search(array, 0, a - 1, temp);
            if(array[found] == temp)
                ++count;
        }
        printf("%d\n", count);
        count = 0;
        scanf("%d %d", &a, &b);
    }
    return 0;
}
    
    
