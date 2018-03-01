// Main Program File
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "header.h"

int main()
{    main_UI();
    // Variable Declarations
    /*FILE *fptr_plain,        // fptr_plain => input file (plain)
         *fptr_encrypt,      // fptr_encrypt => output file (encrypted)
         *fptr_decrypt;      // fptr_decrypted => decrypted file (plain)

    int bin_message[64];
    int sub_key[16][48];
    int text_count = 0, i, j;
    char fchar;
    unsigned char key[] = "HEXKEY12";

    bool en_exit_state = false,     //encryption state
         de_exit_state = false;     //decryption state

    // Open Files for encryption
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

    // Encryption Loop
    while (! en_exit_state)
    {
        char txt_message[8] = {'\0'};      // array to read from file, initialized to 0

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

        tobin(txt_message, bin_message);        // convert text to binary

        encryption(bin_message,sub_key);        //encryption function

        // write encrypted message to file
        for(i = 0; i < 64; i++)
        {
            fprintf(fptr_encrypt, "%d", bin_message[i]);
        }
    }

    // close encryption files
    fclose(fptr_plain);
    fclose(fptr_encrypt);

    //Open files for decryption
    fptr_encrypt = fopen("encryption.txt", "r");
    fptr_decrypt = fopen("decryption.txt", "w");

    // File Unavailable Message
    if (fptr_encrypt == NULL)
    {
        printf("File not available!!");
        exit(1);
    }

    // variables for decryption
    int deci_text[8];            //text in ascii value
    char fchar2;

    // Decryption Loop
    while(! de_exit_state)
    {
        int decr_message[64] = {0};

        // Get input from file
        for(i = 0; i < 64; i++)
        {
            fchar2 = getc(fptr_encrypt);

            if (fchar2 == EOF)
            {
                de_exit_state = true;
                break;
            }

            decr_message[i] = atoi(&fchar2);
        }

        decryption(decr_message,sub_key);       // Decryption Function
        todeci(decr_message, deci_text);        // binary to decimal(ascii)

        // Write decrypted message to file
        for (j = 0; j < 8; j++)
        {
            fprintf(fptr_decrypt, "%c", deci_text[j]);
        }
    }

    // Close Decryption Files
    fclose(fptr_encrypt);
    fclose(fptr_decrypt);*/

    return 0;
}
