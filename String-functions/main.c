#include "heading.h"

int main()
    {
    // puts
    char puts_str[LEN_STR] = "A1B2C3D4";

    printf("Puts:");

    puts(puts_str);

    printf("-----------------------------\n");
    // strchr
    char k = '1';

    char strchr_str[LEN_STR] = "This 1s sparta!";

    int Noumber_str;

    Noumber_str = strchr(strchr_str, k);

    printf("Strchr: %d \n", Noumber_str);

    printf("-----------------------------\n");
    // strcpy
    char strcpy_str1[LEN_STR] = "Copy this text";

    char strcpy_str2[LEN_STR];

    strcpy(strcpy_str1, strcpy_str2);

    printf("Strcpy:");

    puts(strcpy_str2);

    printf("-----------------------------\n");
    // strncpy
    int Quantity_strcpy = 5;

    char strncpy_str1[LEN_STR] = "Copy this text";

    char strncpy_str2[LEN_STR];

    strncpy(strncpy_str1, strncpy_str2, Quantity_strcpy);

    printf("Strncpy:");

    puts(strncpy_str2);

    printf("-----------------------------\n");
    // strcat
    char strcat_str1[LEN_STR] = "I love you ";

    char strcat_str2[LEN_STR] = "and C";

    strcat(strcat_str1, strcat_str2);

    printf("Strcat:");

    puts(strcat_str1);

    printf("-----------------------------\n");
    // strncat
    int Quantity_strncat = 3;

    char strncat_str1[LEN_STR] = "I love ";

    char strncat_str2[LEN_STR] = "you and C";

    strncat(strncat_str1, strncat_str2, Quantity_strncat);

    printf("Strncat:");

    puts(strncat_str1);

    printf("-----------------------------\n");

    // fgets
    FILE *my_file;

    my_file = fopen("test.txt","r");

    char fgets_str1[LEN_STR];

    int Quantity_fgets = 23;

    printf("Fgets:");

    puts( fgets(fgets_str1, Quantity_fgets, my_file));

    printf("-----------------------------\n");

    //  strdup
    char strdup_srtr1[LEN_STR] = "I don't need to know the amount of data :-)";

    printf("Strdup:");

    puts (strdup(strdup_srtr1));

    printf("-----------------------------\nThe test is over");

    return 0;

    }
