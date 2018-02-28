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
