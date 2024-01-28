#include <stdio.h>
#include <memory.h>

int main()
{
    int arr[3] = {1,2,3};
    int length = sizeof(arr) /  (arr[0]);
    printf("数组大小: %d, 长度: %d, 内存地址: %p \n", sizeof(arr), length, (void*)&arr);
    return 0;
}