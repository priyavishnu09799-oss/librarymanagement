#include <stdio.h>
#include "lib.h"

void view_all_books(void)
{
    FILE *fp;
    Book b;

    fp = fopen("books.dat", "rb");

    if(fp == NULL)
    {
        printf("No books found!\n");
        return;
    }

    printf("\n========== ALL BOOKS ==========\n");

    while(fread(&b, sizeof(Book), 1, fp))
    {
        printf("\nBook ID   : %d", b.book_id);
        printf("\nBook Name : %s", b.title);
        printf("\nAuthor    : %s", b.author);
        printf("\nQuantity  : %d\n", b.quantity);
    }

    fclose(fp);
}
