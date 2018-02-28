void funct(int message1[],int message2[],int message3[]){
    for(int i = 0; i < 32; i++){
        message3[i] = message1[i] ^ message3[i];
    }
}
//function for adding two half of message in a reverse order
void reverse_order(int message[],int left_half[],int right_half[]){
    for (int i = 0 ; i < 32; i++){
        message[i] = right_half[i];
        message[32+i] = left_half[i];
    }
}
//function for encrypting data
void encryption(int message[],int subkey[][48])
{

    int left_half[32],right_half[32],temp_first[32],temp_second[32];
    init_permute(message);
    array_sub(message,left_half);
    array_sub(&message[32],right_half);
    for (int i = 0  ; i < 16 ; i++){
        array_sub(right_half,temp_first);
        array_sub(temp_first,temp_second);
        round_function(temp_second,subkey[i]);
        funct(left_half,temp_second,right_half);
        array_sub(temp_first,left_half);
    }
    reverse_order(message,left_half,right_half);
    final_permute(message);
}
void decryption(int message[],int subkey[][48])
{

    int left_half[32],right_half[32],temp_first[32],temp_second[32];

    init_permute(message);
    array_sub(message,left_half);
    array_sub(&message[32],right_half);
    for (int i = 15  ; i >= 0 ; i--){
        array_sub(right_half,temp_first);
        array_sub(temp_first,temp_second);
        round_function(temp_second,subkey[i]);
        funct(left_half,temp_second,right_half);
        array_sub(temp_first,left_half);
    }
    reverse_order(message,left_half,right_half);
    final_permute(message);
}
