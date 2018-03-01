// Main Program File

#include "header.h"

int main()
{
    printf("Hello world!\n");

    // Variable Declarations
    FILE *fptr_plain,        // fptr_plain => input file (plain)
         *fptr_encrypt,      // fptr_encrypt => output file (encrypted)
         *fptr_decrypt;      // fptr_decrypted => decrypted file (plain)

    int bin_message[64], decrypt_msg[8];
    int sub_key[16][48];
    int text_count = 0, i, j;

    char fchar;
    char key[] = "HEXKEY12";

    bool en_exit_state = false,
         de_exit_state = false;

    // Open Files
    fptr_plain = fopen("text.txt", "r");
    fptr_encrypt = fopen("encryption.txt", "w");

    // File Unavailable Message
    if (fptr_plain == NULL)
    {
        printf("File not available!!");
        exit(1);
    }

    // Generate Sub-keys
    DES_key(key,sub_key);

    // Program Loop
    while (! en_exit_state)
    {
        char txt_message[8] = {'\0'};      //

        for (text_count = 0; text_count < 8; text_count++)
        {
            fchar = getc(fptr_plain);

            if (fchar == EOF)
            {
                en_exit_state = true;
                break;
            }

            txt_message[text_count] = fchar;
        }

        tobin(txt_message, bin_message);
        printf("Before encryption\n");
        for(i = 0; i < 64; i++){
            printf("%d",bin_message[i]);
        }
        printf("\n");
        printf("After encryption\n");
        encryption(bin_message,sub_key);
        for (i = 0; i < 64;i++)
        {
            printf("%d",bin_message[i]);
        }
        printf("\n");

        for(i = 0; i < 64; i++)
        {
            fprintf(fptr_encrypt, "%d", bin_message[i]);
        }
    }
    fclose(fptr_plain);
    fclose(fptr_encrypt);

    fptr_encrypt = fopen("encryption.txt", "r");
    fptr_decrypt = fopen("decryption.txt", "w");

    char o;
    while(! de_exit_state)
    {
        int dec_message[64] = {0};

        for(i = 0; i < 64; i++)
        {
            o = getc(fptr_encrypt);

            if (o == EOF)
            {
                de_exit_state = true;
                break;
            }

            dec_message[i] = atoi(&o);
            printf("%d", dec_message[i]);
        }

        //printf("After decryption\n");
        decryption(dec_message,sub_key);
        todeci(dec_message, decrypt_msg);

        for (j = 0; j < 8; j++)
        {
            fprintf(fptr_decrypt, "%c", decrypt_msg[j]);
        }
        /*for(i = 0; i < 64; i++)
        {
            printf("%d",dec_message[i]);
        }*/
    }

    fclose(fptr_encrypt);
    fclose(fptr_decrypt);

    return 0;
}
