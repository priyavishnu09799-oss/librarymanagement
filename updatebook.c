
#include <stdio.h>
#include "lib.h"

void update_book(void)
{
    FILE *fp;
    Book b;
    int id;

    printf("\n========== UPDATE BOOK ==========\n");

    printf("Enter Book ID: ");
    scanf("%d", &id);
    clear_input_buffer();

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
            printf("Enter New Book Name: ");
            read_line(b.title, TITLE_LEN);

            printf("Enter New Author Name: ");
            read_line(b.author, AUTHOR_LEN);

            printf("Enter New Quantity: ");
            scanf("%d", &b.quantity);

            fseek(fp, -sizeof(Book), SEEK_CUR);
            fwrite(&b, sizeof(Book), 1, fp);

            printf("\nBook updated successfully!\n");

            fclose(fp);
            return;
        }
    }

    printf("\nBook ID not found!\n");

    fclose(fp);
}
