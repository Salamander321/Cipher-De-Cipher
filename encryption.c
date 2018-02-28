void encryption(int message[],int subkey[][48])
{
    int *left_half,*right_half;
    //left_half = (int *) malloc(sizeof(int) * 32);
    //right_half = (int *) malloc(sizeof(int) * 32);
    init_permute(message);
    left_half = &message[0];
    right_half = &message[32]
}
