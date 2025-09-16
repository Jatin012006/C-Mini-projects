// Student marks system
/*  1. Add student
    2. View all students
    3. Search student
    4. Calculate total & average
    5. Find topper
    6. Update marks
    7. Delete student
    8. Exit
*/

#include<stdio.h>
#include<string.h>

struct student
{
    int roll;
    char name[50];
    float marks;
};

int stdcount = 0;
struct student stds[100];
void addstd()
{
    printf("Welcome to students details adding pannel\n\n");
    printf("Fill details to add a student\n");

    printf("Enter roll no: ");
    scanf("%d", &stds[stdcount].roll);
    printf("Enter name: ");
    scanf("%s", stds[stdcount].name);
    printf("Enter marks: ");
    scanf("%f", &stds[stdcount].marks);
    stdcount++;
    printf("Student added successfully\n");
    printf("\n");
}

void view()
{
    for (int i = 0; i < stdcount;i++)
    {
        printf("Roll: %d\n", stds[i].roll);
        printf("Name: %s\n", stds[i].name);
        printf("Marks: %f\n", stds[i].marks);
    }
}

void search()
{
    printf("_Welcome to search bar_\n");
    printf("1: Search by ID\n2: Search by NAME\n");
    int search;
    scanf("%d", &search);

    if (search == 1)
    {
        int id;
        printf("Enter std ID: ");
        scanf("%d", &id);
        for (int i = 0; i < stdcount; i++)
        {
            if (id == stds[i].roll)
            {
                printf("Found %s roll no %d having marks %.2f\n", stds[i].name, stds[i].roll, stds[i].marks);
                return;
            }
        }
        printf("Student not found with this ID.\n");
    }
    else if ( search == 2)
    {
        char sname[50];
        printf("Enter std name: ");
        scanf("%s", sname);
        if (strcmp(sname,stds[stdcount].name) == 0)
        {
            printf("Found %s roll no %d having marks %d\n",stds[stdcount].name, stds[stdcount].roll, stds[stdcount].marks);
        }
    }
    else
        printf("Error student not found: INVALID DETAILS\n");
}

void avg()
{
    float total = 0, avg;
    for (int i = 0; i < stdcount; i++)
    {
        total += stds[i].marks;
    }
    avg = total / stdcount;
    printf("The avg marks of students is: %f\n", avg);
}

void topper()
{
    if (stdcount == 0) {
        printf("No students added yet.\n");
        return;
    }

    float highestMarks = stds[0].marks;
    int topperIndex = 0;

    for (int i = 1; i < stdcount; i++)
    {
        if (stds[i].marks > highestMarks)
        {
            highestMarks = stds[i].marks;
            topperIndex = i;
        }
    }

    printf("Topper: %s\n", stds[topperIndex].name);
    printf("Roll No: %d\n", stds[topperIndex].roll);
    printf("Marks: %f\n", stds[topperIndex].marks);
}

void update()
{
    printf("Welcome to update marks tab\n");
    int rno;
    float umarks;
    printf("Enter ur roll no to update ur marks: ");
    scanf("%d", &rno);
    for (int i = 0; i < stdcount; i++)
    {
        if (rno == stds[i].roll)
        {
            printf("Student Found\n");
            printf("Enter updated marks: ");
            scanf("%f", &umarks);
            stds[i].marks = umarks;
            printf("marks updated to: %f\n",umarks);
        }
    }
}

/* void delete()
{
    printf("Delete Students Data\n");
    int drno;
    printf("Enter roll no to del students data: ");
    scanf("%d", &drno);
    for (int i = 0; i < stdcount; i++)
    {
        if ( drno == stds[i].roll)
        {

        }
    }
}
*/

int main()
{
    while (1)
    {
        printf("\n=====Student marks management menu=====\n\n");
        printf("1. Add studemt\n2. View all student\n3. Search student\n4. Calculate average\n5. Find topper\n6. Update marks\n7. Exit the system\n");
        printf("\nEnter ur choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: addstd(); break;
            case 2: view(); break;
            case 3: search(); break;
            case 4: avg(); break;
            case 5: topper(); break;
            case 6: update(); break;
            case 7: return 0;
        }
    }
}