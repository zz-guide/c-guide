#include <stdio.h>
#include <memory.h>

int main()
{
    int arr[3] = {1,2,3};
    int length = sizeof(arr) /  (arr[0]);
    for (int i = 0; i < length; i++) {
        printf("第%d 个元素:%d \n", i+1, arr[i]);
    }
    
    return 0;
}