#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct employee {
    char name[50];
    int age;
    float salary;
    char job_title[50];
    int id;
    struct employee *next;
};

struct employee *head = NULL;

void add_employee() {
    struct employee *new_employee = (struct employee *)malloc(sizeof(struct employee));
    printf("Enter name: ");
    gets(new_employee->name);
    printf("Enter age: ");
    char age_str[10];
    gets(age_str);
    new_employee->age = atoi(age_str);
    printf("Enter salary: ");
    char salary_str[20];
    gets(salary_str);
    new_employee->salary = atof(salary_str);
    printf("Enter job title: ");
    gets(new_employee->job_title);
    printf("Enter ID: ");
    char id_str[10];
    gets(id_str);
    new_employee->id = atoi(id_str);
    new_employee->next = NULL;
    if (head == NULL) {
        head = new_employee;
        return;
    }
    struct employee *current_employee = head;
    while (current_employee->next != NULL) {
        current_employee = current_employee->next;
    }
    current_employee->next = new_employee;
}

void delete_employee() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Enter ID of employee to delete: ");
    char id_str[10];
    gets(id_str);
    int id = atoi(id_str);
    if (head->id == id) {
        struct employee *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct employee *current_employee = head;
    while (current_employee->next != NULL) {
        if (current_employee->next->id == id) {
            struct employee *temp = current_employee->next;
            current_employee->next = current_employee->next->next;
            free(temp);
            return;
        }
        current_employee = current_employee->next;
    }
    printf("Employee with ID %d not found.\n", id);
}

void modify_employee()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Enter ID of employee to modify: ");
    char id_str[10];
    gets(id_str);
    int id = atoi(id_str);
    struct employee *current_employee = head;
    while (current_employee != NULL)
    {
        if (current_employee->id == id)
        {
            printf("Enter new name (leave blank to keep '%s'): ", current_employee->name);
            char new_name[50];
            gets(new_name);
            if (strlen(new_name) > 0)
            {
                strcpy(current_employee->name, new_name);
            }
            printf("Enter new age (leave blank to keep '%d'): ", current_employee->age);
            char new_age_str[10];
            gets(new_age_str);
            if (strlen(new_age_str) > 0)
            {
                current_employee->age = atoi(new_age_str);
            }
            printf("Enter new salary (leave blank to keep '%.2f'): ", current_employee->salary);
            char new_salary_str[20];
            gets(new_salary_str);
            if (strlen(new_salary_str) > 0)
            {
                current_employee->salary = atof(new_salary_str);
            }
            printf("Enter new job title (leave blank to keep '%s'): ", current_employee->job_title);
            char new_job_title[50];
            gets(new_job_title);
            if (strlen(new_job_title) > 0)
            {
                strcpy(current_employee->job_title, new_job_title);
            }
            printf("Employee with ID %d modified.\n", id);
            return;
        }
        current_employee = current_employee->next;
    }
    printf("Employee with ID %d not found.\n", id);
}

void view_employee()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Enter ID of employee to view: ");
    char id_str[10];
    gets(id_str);
    int id = atoi(id_str);
    struct employee *current_employee = head;
    while (current_employee != NULL)
    {
        if (current_employee->id == id)
        {
            printf("Name: %s\n", current_employee->name);
            printf("Age: %d\n", current_employee->age);
            printf("Salary: %.2f\n", current_employee->salary);
            printf("Job Title: %s\n", current_employee->job_title);
            printf("ID: %d\n", current_employee->id);
            return;
        }
        current_employee = current_employee->next;
    }
    printf("Employee with ID %d not found.\n", id);
}

void view_all_employees()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct employee *current_employee = head;
    while (current_employee != NULL)
    {
        printf("Name: %s\n", current_employee->name);
        printf("Age: %d\n", current_employee->age);
        printf("Salary: %.2f\n", current_employee->salary);
        printf("Job Title: %s\n", current_employee->job_title);
        printf("ID: %d\n", current_employee->id);
        printf("\n");
        current_employee = current_employee->next;
    }
}
