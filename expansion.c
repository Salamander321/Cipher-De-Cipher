//Expansion File

//table for expansion
int expand_table[8][6] ={{32,  1,  2,  3,  4,  5},
                         { 4,  5,  6,  7,  8,  9},
                         { 8,  9, 10, 11, 12, 13},
                         {12, 13, 14, 15, 16, 17},
                         {16, 17, 18, 19, 20, 21},
                         {20, 21, 22, 23, 24, 25},
                         {24, 25, 26, 27, 28, 29},
                         {28, 29, 30, 31, 32,  1}
                        };

//function to expand 32 bit to 48 bit
void expansion(int *data_32, int*data_48)
{
    int index_32;
    int index_48 = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            index_32 = expand_table[i][j];
            data_48[index_48++] = data_32[index_32];
        }
    }
}
