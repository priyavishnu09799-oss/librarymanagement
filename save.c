#include <stdio.h>
#include "lib.h"

void save_all(void)
{
    FILE *fp;
    Book b;

    fp = fopen("books.dat", "rb");

    if(fp == NULL)
    {
        printf("No books found!\n");
        return;
    }

    printf("\n========== SAVE ==========\n");

    while(fread(&b, sizeof(Book), 1, fp))
    {
        printf("Book ID   : %d\n", b.book_id);
        printf("Book Name : %s\n", b.title);
        printf("Author    : %s\n", b.author);
        printf("Quantity  : %d\n", b.quantity);
    }

    fclose(fp);

    printf("\nBooks saved successfully!\n");
}
