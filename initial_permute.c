// Initial Permutation File

void init_permute(int *mptr)            // mptr => message pointer; pointer to message array
{
    int ip_message[8][8], i, j;         // ip_message => initial permuted message

    // permute message to ip_message
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            ip_message[i][j] = *(mptr + init_p_table[i][j]);
        }
    }

    // assign ip_message to array passed in the function
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            *(*(mptr + i) + j) = ip_message[i][j];
        }
    }

    return ;
}




