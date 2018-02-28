
#include "header.h"
#include "global_variables.h"

int main()
{
    printf("Hello world!\n");
    char message1[] = "01234567";
    int message[64];
    int sub_key[16][48];
    int key_56[56];
    int key_64[64] = {0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1};
    key_permute(key_64,key_56);
    subkey_generation(key_56,sub_key);
    tobin(message1,message);
    encryption(message,sub_key);
    for (int i = 0; i < 64;i++)
    {
        printf("%d",message[i]);
    }

    return 0;
}
