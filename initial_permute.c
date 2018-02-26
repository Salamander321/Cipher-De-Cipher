// Initial Permutation File

void init_permute(int msg[64])            // msg => array of message read from file
{
    int ip_message[64], i, j;         // ip_message => initial permuted message

    // permute message to ip_message
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            ip_message[8 * i + j] = msg[init_p_table[i][j]];
        }
    }

    // assign ip_message to array passed in the function
    for (i = 0; i < 64; i++)
    {
        msg[i] = ip_message[i];
    }

    return;
}
