#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <txlib.h>
#include <malloc.h>
#include "functions.cpp"

#define Additionally_Memory 1
#define UNNECESSARY_CHARACTERS 65
#define ERROR_OPEN_FILE 303

int Str_Compare_Front(char* str1, char* str2);
int Str_Compare_Revers(char* str1, char* str2);
void Check_Open_File(FILE* file);
void Size_Buffer_and_Index(FILE* My_File, int* Len_Index, int* Len_Str);
void Index_Arr_From_Buffer(char** Index_Arr, char* BUF, FILE* My_File);
void Str_Sorter(char** Index_Arr, const int size_index, int (*Str_Compare)(char*, char*));
void Str_Print(char** Index_Arr, const int size_index);
void Str_Print_In_File(char** Index_Arr, const int size_index, FILE* File_Return);
