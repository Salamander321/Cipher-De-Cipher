int permutekey__table[8][7] ={ {57 , 49 , 41 , 33 , 25 , 17 , 9}, //permutation tale for changing 64 bit key to 56 bit.
                         {1 , 58 , 50 , 42 , 34 , 26 , 18},
                         {10 , 2 , 59 , 51 , 43 , 35 , 27},
                         {19 , 11 , 3 , 60 , 52 , 44 , 36},
                         {63 , 55 , 47 , 39 , 31 , 23 , 15},
                         {7 , 62 , 54 , 46 , 38 , 30 , 22},
                         {14 , 6 , 61 , 53 , 45 , 37 , 29},
                         {21 , 13 , 5 , 28 , 20 , 12 , 4}};
int permutesubkey_table[8][6] ={{14 , 17 , 11 , 24 , 1 , 5}, //permutation table for sub keys.
                                {3 , 28 , 15 , 6 , 21 , 10},
                                {23 , 19 , 12 , 4 , 26 , 8},
                                {16 , 7 , 27 , 20 , 13 , 2},
                                {41 , 52 , 31 , 37 , 47 , 55},
                                {30 , 40 , 51 , 45 , 33 , 48},
                                {44 , 49 , 39 , 56 , 34 , 53},
                                {46 , 42 , 50 , 36 , 29 , 32}};

//function of changing key from 64 bit to 56 bit
void key_permute(int *key_unpermute,int *key_permuted)
{
int index_permute = 0;
int index_unpermute;
for (int i = 0; i <8;i++){
    for (int j = 0; j<7;j++){
        index_unpermute = permutekey__table[i][j] - 1;
        key_permuted [index_permute++] = key_unpermute[index_unpermute];
    }
}
}
//function that generate 16 sub key of 48 size from 56 bit permuted key
void subkey_generation(int *key_56,int subkey_16[][48])
{   int left_half[17][28],right_half[17][28];
    int unpermuted_subkey[16][56];
    int shift,index1,index2,index_permuted_subkey,index_unpermuted;
    for (int i = 0; i < 56/2; i++) //loop for dividing 56 bit key into two equal halves.
    {
        left_half[0][i] = key_56[i];
        right_half[0][i] = key_56[28+i];
        }

    for (int i =1; i < 17;i++) //loop for shifting that generate 16 sub sub key halves.
        {
        index1 = 0;
        index2 = 0;
        if (i == 1 || i == 2 || i == 9 ||i == 16)
            shift = 1;
        else
            shift = 2;
        while (index1 < 28){
            while (index1 < 28-shift){
                left_half[i][index1] = left_half[i-1][index1+shift];
                right_half[i][index1] = right_half[i-1][index1+shift];
                index1++;
            }
        left_half[i][index1] = left_half[i-1][index2];
        right_half[i][index1] = right_half[i-1][index2];
        index1++;
        index2++;
        }
    }

    for (int i = 0; i < 16; i++)// loop that combine left and right halves of key.
        {
        for (int j = 0; j < 28; j++){
            unpermuted_subkey[i][j] = left_half[i+1][j];
            unpermuted_subkey[i][28+j] = right_half[i+1][j];

        }
    }

    for (int i = 0; i < 16; i++) // loop that permutes 56 bit sub key into 48 bit sub key.
        {
        index_permuted_subkey = 0;
        for(int j = 0; j < 8;j++){
            for (int k = 0; k < 6;k++){
                index_unpermuted = permutesubkey_table[j][k]-1;
                subkey_16[i][index_permuted_subkey] = unpermuted_subkey[i][index_unpermuted];
                index_permuted_subkey++;
            }
        }
    }
}
