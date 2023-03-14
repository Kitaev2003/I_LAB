#include "heading.h"


int main()
{
    FILE* My_File;

    FILE* File_Return1;

    FILE* File_Return2;

    My_File  = fopen("input_text.txt", "r");

    Check_Open_File(My_File);

    File_Return1 = fopen("result_front.txt", "w");

    Check_Open_File(File_Return1);

    File_Return2 = fopen("result_revers.txt", "w");

    Check_Open_File(File_Return2);

    char** index_arr;
    char* text_buffer;

    int len_index = 0;
    int len_buffer = 0;

    Size_Buffer_and_Index(My_File, &len_index, &len_buffer);

    text_buffer = (char*) calloc(len_buffer + Additionally_Memory, sizeof(char));

    index_arr = (char**) calloc(len_index + Additionally_Memory, sizeof(char*));

    Index_Arr_From_Buffer(index_arr, text_buffer, My_File);

    fclose(My_File);

    free(text_buffer);

    Str_Sorter(index_arr, len_index, Str_Compare_Front);

    Str_Print(index_arr, len_index);

    Str_Print_In_File(index_arr, len_index, File_Return1);

    fclose(File_Return1);

    Str_Sorter(index_arr, len_index, Str_Compare_Revers);

    Str_Print_In_File(index_arr, len_index, File_Return2);

    free(index_arr);

    fclose(File_Return2);

    return 0;
}


