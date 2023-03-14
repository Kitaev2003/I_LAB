int strlen(const char* str)
    {
    int i = 0;

    while (str[i] != '\0')
        {
            i++ ;
        }
    return i;
    }

int puts(const char* str)
    {
    printf("%s \n", str);

    return 0;
    }

int strchr(char* str, const char symbol)
    {
    int i = -1;

    while (str[i] != symbol)
        {
        i++ ;
        }

    if (i+1 > 0 && i < (strlen(str)) )
        {
        return i+1;
        }

    else
        {
        return 0;
        }

    }

char* strcpy(const char* destination, char* source)
    {
    int i = 0;

    while (destination[i] != '\0')
        {
         source[i] = destination[i];
         i++;
        }
    source[i++] = '\0';
    return source;
    }

char* strncpy(char* destination, char* source, const int num)
    {
    int i = 0;

    while (i < num && destination[i] != '\0')
        {
        source[i] = destination[i];
        i++;
        }
    source[i++] = '\0';
    return source;
    }

char* strcat(char* destination, const char* append)
    {
    int len_destination = strlen(destination);

    int len_append = strlen(append);

    for (int i = 0; i < len_append ; i++)
        {
        destination[len_destination] = append[i];
        len_destination++;
        }
    return destination;
    }

char* strncat(char* destination, const char* append, const int num)
    {
    int len_destination = strlen(destination);

    int len_append = strlen(append);

    for (int i = 0; i < num  && i < len_append ; i++)
        {
        destination[len_destination+i] = append[i];
        len_append++;
        }
    return destination;
    }

char* fgets (char *str, int n, FILE *stream)
    {
    int i = 0;

    str[i] = getc(stream);

    while (str[i] != EOF && i != n)
        {
        i++;
        str[i] = getc(stream);
        }

    if (i > 0)
        {
        str[i++] = '\0';
        return str;
        }

    else
        {
        return NULL;
        }
    }

char* strdup(char *str)
    {
    char *copystr = (char*)calloc(sizeof(str), 1);

    int i = 0;

    while (str[i] != '\0')
        {
         copystr[i] = str[i];
         i++;
        }
    copystr[i++] = '\0';

    return copystr;
    }
