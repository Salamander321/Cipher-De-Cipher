
#include "header.h"

int main()
{
    printf("Hello world!\n");
    int arr[48] = {1,0,1,1,0,1,1,1,1,0,1,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1,1,0,0,1,1,1,0,0,0,0,1,0,1,0,11,1,0,0,1,1};
        int arr2[32];
        substitution(arr,arr2);
        printf("\n");
        for (int i = 0; i <32;i++)
        {   if ((i) % 4 == 0)
                printf("\n");
            printf("%d\t",arr2[i]);
        }
    return 0;
}
