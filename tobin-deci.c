// read 8 bytes character block from file and convert to binary array

void tobin(char c[8], int bin[64])
{
    int i, j, k;
    for (i = 0; i < 8; i++)
    {
        for (j = sizeof(char) * 8 - 1, k = 0; j >= 0; j--, k++)
        {
            (c[i] & (1u << j) )? (bin[i * 8 + k] = 1) : (bin[i * 8 + k] = 0);
        }
    }
    return;
}

// binary to decimal function
void todeci(int bin[64], int ascii_text[8])
{
    int i, j, k;

    for (i = 0; i < 8; i++)
    {
        ascii_text[i] = '\0';
        for(j = 0, k = 7; j < 8; j++, k--)
        {
            ascii_text[i] = ascii_text[i] + (bin[(i * 8 + k)] * pow(2, j));
        }
    }

    return;
}
