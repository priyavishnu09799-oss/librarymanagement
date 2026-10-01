#include <stdio.h>
#include "lib.h"

void add_book(void)
{
    FILE *fp;
    Book b;

    printf("\n========== ADD NEW BOOK ==========\n");

    printf("Enter Book ID: ");
    scanf("%d", &b.book_id);
    clear_input_buffer();

    if(book_exists(b.book_id))
    {
        printf("Book ID already exists!\n");
        return;
    }

    printf("Enter Book Name: ");
    read_line(b.title, TITLE_LEN);

    printf("Enter Author Name: ");
    read_line(b.author, AUTHOR_LEN);

    printf("Enter Quantity: ");
    scanf("%d", &b.quantity);
    clear_input_buffer();

    fp = fopen("books.dat", "ab");

    if(fp == NULL)
    {
        printf("File opening error!\n");
        return;
    }

    fwrite(&b, sizeof(Book), 1, fp);

    fclose(fp);

    printf("\nBook added successfully!\n");
}
