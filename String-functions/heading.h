#include <stdlib.h>
#include <stdio.h>
#include "functions.c"
#define LEN_STR 100
int puts(const char* str);
int strlen(const char* str);
int strchr(char* str, const char symbol);
char* strcpy(const char* destination, char* source);
char* strncpy(char* destination, char* source, const int num);
char* strcat(char* destination, const char* append);
char* strncat(char* destination, const char* append, const int num);
char* fgets (char *str, int n, FILE *stream);
char* strdup(char *str);
