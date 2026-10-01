#include <stdio.h>
#include "lib.h"

void return_book(void)
{
    FILE *fp;
    Book b;
    int id;

    printf("\n========== ISSUE BOOK ==========\n");

    printf("Enter Book ID: ");
    scanf("%d", &id);

    fp = fopen("books.dat", "rb+");

    if(fp == NULL)
    {
        printf("File opening error!\n");
        return;
    }

    while(fread(&b, sizeof(Book), 1, fp))
    {
        if(b.book_id == id)
        {
            if(b.quantity > 0)
            {
                b.quantity--;

                fseek(fp, -sizeof(Book), SEEK_CUR);
                fwrite(&b, sizeof(Book), 1, fp);

                printf("\nBook issued successfully!\n");
            }
            else
            {
                printf("\nBook is not available!\n");
            }

            fclose(fp);
            return;
        }
    }

    printf("\nBook ID not found!\n");

    fclose(fp);
}
