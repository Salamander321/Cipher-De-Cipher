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
#include "initial_permute.c"
#include "final_permute.c"

void expansion(int *,int*);
void substitution( int [],int []);
void key_permute(int*,int*);
void subkey_generation(int* , int a[][48]);
void subkey_permute(int*,int*);
void subkey_shift(int*,int*,int[][56]);
void final_permute(int [64]);
void init_permute(int [64]);

#endif // HEADER_H_INCLUDED



