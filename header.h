#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#pragma once

// Included Header File
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>

// Included Project Files
#include "Substitution.c"
#include "key.c"
#include "expansion.c"
#include "permutation.c"
#include "tobin.c"
#include "roundfunction.c"
#include "encryption.c"
#include "UI.c"
#include "file_encrypt.c"

// Functions Prototypes
int keys(int );
void logo();
void box();
void encryption_screen();
void box_input(int x, int y);
int confirm_screen();
void decryption_screen();
void main_UI();
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
void todeci(int [], int []);
void array_sub(int [],int []);
void reverse_order(int [],int [],int []);
void funct(int [],int [],int []);
void encryption(int [],int [][48]);
void decryption(int [],int [][48]);
void DES_key(char [],int [][48]);
void file_encrypt(char [],char [], char []);
void file_decrypt(char [],char [], char []);
void succesfull();


#endif // HEADER_H_INCLUDED
