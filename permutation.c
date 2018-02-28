// Initial Permutation

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

// Final Permutation

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

// 32bit Permutation after S-box

void permute_sbox(int sbox_out[32])
{
    int i, temp[32];

    // store permuted array in temp
    for(i = 0; i < 32; i++)
    {
        temp[i] = sbox_out[sbox_p_table[i] - 1];
    }

    // assign permuted array to input array
    for(i = 0; i < 32; i++)
    {
        sbox_out[i] = temp[i];
    }

    return;
}
