#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mysteryExplode(const char *string, char **dest, int *length);
void mysteryImplode(char **string, const char *dest, int length);

int main()
{
    char *string;
    char *dest;
    int length;

    string = (char *)malloc(100);
    dest = (char *)malloc(100);

    scanf("%s", string);
    mysteryExplode(string, &dest, &length);
    printf("%s\n", dest);
    mysteryImplode(&string, dest, length);
    printf("%s\n", string);

    free(string);
    free(dest);

    return 0;
}

void mysteryExplode(const char *string, char **dest, int *length)
{
    int i, j, k;
    int stringLength = strlen(string);

    *length = stringLength * 2 - 1;

    for (i = 0, j = 0; i < *length; i++)
    {
        if (i % 2 == 0)
        {
            (*dest)[i] = string[j];
            j++;
        }
        else
        {
            k = i / 2;
            (*dest)[i] = string[k];
        }
    }

    (*dest)[*length] = '\0';
}

void mysteryImplode(char **string, const char *dest, int length)
{
    int i, j, k;

    for (i = 0, j = 0; i < length; i++)
    {
        if (i % 2 == 0)
        {
            (*string)[i] = dest[j];
            j++;
        }
        else
        {
            k = (i + 1) / 2;
            (*string)[k] = dest[i];
        }
    }

    (*string)[length] = '\0';
}
