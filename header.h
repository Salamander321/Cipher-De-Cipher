#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include "Substitution.c"
#include "key.c"
#include "expansion.c"
#include "permutation.c"
#include "tobin.c"
#include "roundfunction.c"

void expansion(int *,int*);
void substitution( int [],int []);
void key_permute(int*,int*);
void subkey_generation(int* , int a[][48]);
void subkey_permute(int*,int*);
void subkey_shift(int*,int*,int[][56]);
void final_permute(int [64]);
void init_permute(int [64]);
void permute_sbox(int [32]);
void tobin(char [8], int [64]);
void array_sub(int [],int []);
void reverse_order(int [],int [],int []);
void funct(int message1[],message2[],message3[]);


#endif // HEADER_H_INCLUDED
