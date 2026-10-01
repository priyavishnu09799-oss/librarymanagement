#include <stdio.h>
#include <string.h>
#include "lib.h"

void clear_input_buffer(void)
{
    int c;

    while((c = getchar()) != '\n' && c != EOF);
}

void read_line(char str[], int size)
{
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

int book_exists(int id)
{
    FILE *fp;
    Book b;

    fp = fopen("books.dat", "rb");

    if(fp == NULL)
        return 0;

    while(fread(&b, sizeof(Book), 1, fp))
    {
        if(b.book_id == id)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}
