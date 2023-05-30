#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int choice;
    do
    {
        printf("1. Add new employee\n");
        printf("2. Delete employee\n");
        printf("3. Modify employee\n");
        printf("4. View employee\n");
        printf("5. View all employees\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        char choice_str[10];
        gets(choice_str);
        choice = atoi(choice_str);
        switch (choice)
        {
        case 1:
            add_employee();
            break;
        case 2:
            delete_employee();
            break;
        case 3:
            modify_employee();
            break;
        case 4:
            view_employee();
            break;
        case 5:
            view_all_employees();
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
        printf("\n");
    }
    while (choice != 6);
    return 0;
}
