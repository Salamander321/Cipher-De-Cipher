// Final Permutation File

void final_permute(int *mptr)       // mptr => message pointer; pointer to message array
{
    int fp_message[8][8], i, j;           // fp_message => final permuted message

    // permute message to fp_message
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            fp_message[i][j] = *(mptr + final_p_table[i][j]);
        }
    }

    // assign fp_message to the array passed in function
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            *(*(mptr + i) + j) = fp_message[i][j]);
        }
    }
    return;
}

