
#include <stdio.h>
#include "lib.h"

void remove_book(void)
{
    FILE *fp, *temp;
    Book b;
    int id;

    printf("\n========== REMOVE BOOK ==========\n");

    printf("Enter Book ID: ");
    scanf("%d", &id);

    fp = fopen("books.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if(fp == NULL || temp == NULL)
    {
        printf("File opening error!\n");
        return;
    }

    while(fread(&b, sizeof(Book), 1, fp))
    {
        if(b.book_id != id)
        {
            fwrite(&b, sizeof(Book), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("books.dat");
    rename("temp.dat", "books.dat");

    printf("\nBook removed successfully!\n");
}
