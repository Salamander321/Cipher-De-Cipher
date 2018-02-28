// Final Permutation File
#include "global_variables.h"
void final_permute(int msg[64])       // msg => array of final message
{
    int fp_message[64], i, j;           // fp_message => final permuted message

    // permute message to fp_message
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            fp_message[8 * i + j] = msg[final_p_table[i][j]];
        }
    }

    // assign fp_message to the array passed in function
    for (i = 0; i < 64; i++)
    {
        msg[i] = fp_message[i];
    }

    return;
}
