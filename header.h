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
//#include "permutation.c"
//#include "tobin.c"
//#include "roundfunction.c"
#include "encryption.c"

void expansion(int *,int*);
void substitution( int [],int []);
void key_permute(int*,int*);
void subkey_generation(int* , int a[][48]);
void subkey_permute(int*,int*);
void subkey_shift(int*,int*,int[][56]);
void final_permute(int []);
void init_permute(int []);
void permute_sbox(int []);
void tobin(char [], int []);
void array_sub(int [],int []);
void reverse_order(int [],int [],int []);
void funct(int [],int [],int []);
void encryption(int [],int [][48]);

#endif // HEADER_H_INCLUDED
