#include <stdio.h>
#include "lib.h"

void list_issued_books(void)
{
    FILE *fp;
    Book b;

    fp = fopen("books.dat", "rb");

    if(fp == NULL)
    {
        printf("No books found!\n");
        return;
    }

    printf("\n========== ISSUED BOOKS ==========\n");

    while(fread(&b, sizeof(Book), 1, fp))
    {
        if(b.quantity == 0)
        {
            printf("\nBook ID   : %d", b.book_id);
            printf("\nBook Name : %s", b.title);
            printf("\nAuthor    : %s\n", b.author);
        }
    }

    fclose(fp);
}
