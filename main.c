#include <stdio.h>
#include "lib.h"

void main()
{
    int choice;

    while(1)
    {
        printf("\n");
        printf("+----------------------------------------+\n");
        printf("       LIBRARY MANAGEMENT SYSTEM\n");
        printf(" 1. Add New Book \n");
        printf(" 2. Update Book Details \n");
        printf(" 3. Remove Book\n");
        printf(" 4. Search Book\n");
        printf(" 5. View All Books\n");
        printf(" 6. Issue Book\n");
        printf(" 7. Return Book\n");
        printf(" 8. List Issued Books\n");
        printf(" 9. Save \n");
        printf(" 10. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add_book();
                break;

            case 2:
                update_book();
                break;

            case 3:
                remove_book();
                break;

            case 4:
                search_book();
                break;

            case 5:
                view_all_books();
                break;

            case 6:
                issue_book();
                break;

            case 7:
                return_book();
                break;

            case 8:
                list_issued_books();
                break;

            case 9:
                save_all();
                break;

            case 10:
                printf("\nThank you for using Library Management System.\n");
                return;

            default:
                printf("\nInvalid choice! Please enter 1 to 10.\n");
        }
    }
}
