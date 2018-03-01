// Initial permutation table (IP)
int init_p_table[8][8] = {{57, 49, 41, 33, 25, 17,  9, 1},
                          {59, 51, 43, 35, 27, 19, 11, 3},
                          {61, 53, 45, 37, 29, 21, 13, 5},
                          {63, 55, 47, 39, 31, 23, 15, 7},
                          {56, 48, 40, 32, 24, 16,  8, 0},
                          {58, 50, 42, 34, 26, 18, 10, 2},
                          {60, 52, 44, 36, 28, 20, 12, 4},
                          {62, 54, 46, 38, 30, 22, 14, 6}};

// Final permutation table (IP ^ -1)
int final_p_table[8][8] = {{39,  7, 47, 15, 55, 23, 63, 31},
                           {38,  6, 46, 14, 54, 22, 62, 30},
                           {37,  5, 45, 13, 53, 21, 61, 29},
                           {36,  4, 44, 12, 52, 20, 60, 28},
                           {35,  3, 43, 11, 51, 19, 59, 27},
                           {34,  2, 42, 10, 50, 18, 58, 26},
                           {33,  1, 41,  9, 49, 17, 57, 25},
                           {32,  0, 40,  8, 48, 16, 56, 24}};

// 32bit permutation table for s-box output
int sbox_p_table[32] = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10,
                        2, 8, 24, 14, 32, 27,  3,  9, 19, 13, 30, 6, 22, 11, 4, 25};

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
