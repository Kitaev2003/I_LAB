#define UNNECESSARY_CHARACTERS 65
#define ERROR_OPEN_FILE 303

void Size_Buffer_and_Index(FILE* My_File, int* Len_Index, int* Len_Str)
{
    int symbol;

    while((symbol = getc(My_File)) != EOF)
    {
        if(symbol == '\n')
        {
            *Len_Index = *Len_Index + 1;
        }

        *Len_Str = *Len_Str + 1;
    }
    rewind (My_File);

    (*Len_Index)--;
}

void Index_Arr_From_Buffer(char** Index_Arr, char* BUF, FILE* My_File)
{
    int i = 0;

    int k = 0;

    int len = 0;

    while((BUF[i] = getc(My_File)) != EOF)
    {
        if (BUF[i] =='\n')
        {
            BUF[i] ='\0';
            Index_Arr[len] = &(BUF[i-k]);
            k = 0;

            i++;

            len++;

            continue;
        }
        i++;

        k++;
    }
    rewind (My_File);
}

int Str_Compare_Front(char* str1, char* str2)
{
    int k = 0;
    int i = 0;

    if(str1[0] >= 'a')
    {
        str1[i] = str1[0] -'a' + 'A';
    }

    if(str2[0] >= 'a')
    {
        str2[0] = str2[0] -'a' + 'A';
    }

    while(TRUE)
    {
        if (str1[i] > str2[k])
        {
            return 1;
        }

        else if (str1[i] < str2[k])
        {
            return 0;
        }

        else if (str1[i] == '\0')
        {
            return 0;
        }

        else if (str2[k] == '\0')
        {
            return 1;
        }

        i++;
        k++;
    }
}

int Str_Compare_Revers(char* str1, char* str2)
{
    int k = 0;
    int i = 0;
    int len1 = 0;
    int len2 = 0;

    if(str1[0] >= 'a')
    {
        str1[i] = str1[0] -'a' + 'A';
    }

    if(str2[0] >= 'a')
    {
        str2[0] = str2[0] -'a' + 'A';
    }
    while(str1[len1] != '\0')
    {
        len1++;
    }

    while(str2[len2] != '\0')
    {
        len2++;
    }

    if(str1[len1] < UNNECESSARY_CHARACTERS)
    {
        i++;
    }

    if(str2[len2] < UNNECESSARY_CHARACTERS)
    {
        k++;
    }

    while(TRUE)
    {
        if (str1[len1 - i] < str2[len2 - k])
        {
            return 0;
        }

        else if (str1[len1 - i] > str2[len2 - k])
        {
            return 1;
        }

        i++;
        k++;
    }
}

void Str_Sorter(char** Index_Arr, const int size_index, int (*Str_Compare)(char*, char*))
{
    int i = 0;

    int r = 0;

    for(i = 0; i < size_index - 1 ; i++)
    {
        for(r = 0; r < size_index - 1; r++)
        {
            if ( (*Str_Compare) ( Index_Arr[r], Index_Arr[r+1] ) == 1)
            {
                char* transition = Index_Arr[r+1];

                Index_Arr[r+1] = Index_Arr[r];

                Index_Arr[r] = transition;
            }
        }
    }
}

void Str_Print(char** Index_Arr,const int size_index)
{
    int i = 0;

    while(i <= size_index)
    {
        puts(Index_Arr[i]);
        i++;
    }
}

void Str_Print_In_File(char** Index_Arr, const int size_index, FILE* File_Return)
{
    int i = 0;

    while(i < size_index)
    {
        fprintf(File_Return, "%s\n", Index_Arr[i]);
        i++;
    }
}

void Check_Open_File(FILE* file)
{
    if (file == NULL)
    {
        printf("<=====================>ERROR OPENING FILE<=====================>\n\n");
        printf("<============>CHECK THE AVAILABILITY OF YOUR FILE<=============>");
        getch();
        exit(ERROR_OPEN_FILE);
    }
}
