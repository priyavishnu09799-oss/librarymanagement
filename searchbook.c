
#include <stdio.h>
#include "lib.h"

void search_book(void)
{
    FILE *fp;
    Book b;
    int id;

    printf("\n========== SEARCH BOOK ==========\n");

    printf("Enter Book ID: ");
    scanf("%d", &id);

    fp = fopen("books.dat", "rb");

    if(fp == NULL)
    {
        printf("File opening error!\n");
        return;
    }

    while(fread(&b, sizeof(Book), 1, fp))
    {
        if(b.book_id == id)
        {
            printf("\nBook ID   : %d", b.book_id);
            printf("\nBook Name : %s", b.title);
            printf("\nAuthor    : %s", b.author);
            printf("\nQuantity  : %d\n", b.quantity);

            fclose(fp);
            return;
        }
    }

    printf("\nBook ID not found!\n");

    fclose(fp);
}

