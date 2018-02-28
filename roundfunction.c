void round_function(int message[],int key[])
{
    int expanded_message[48],xored_message[48];
    expansion(message,expanded_message);
    for (int i = 0; i < 48;i++)
    {
        xored_message[i] = expanded_message[i] ^ key[i];
    }
    substitution(xored_message,message);
    permute_sbox(message);
}
