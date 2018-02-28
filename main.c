
#include "header.h"
#include "global_variables.h"

int main()
{
    printf("Hello world!\n");
    char message1[] = "Pranavpou";
    int message[64];
    int sub_key[16][48];
    char key[] = "HEXKEY12";
    DES_key(key,sub_key);
    tobin(message1,message);
    printf("Before encryption\n");
    for(int i = 0; i < 64; i++){
        printf("%d",message[i]);
    }
    printf("\n");
    printf("After encryption\n");
    encryption(message,sub_key);
    for (int i = 0; i < 64;i++)
    {
        printf("%d",message[i]);
    }
    printf("\n");
    printf("After decryption\n");
    decryption(message,sub_key);
    for(int i = 0; i < 64; i++){
        printf("%d",message[i]);
    }

    return 0;
}
