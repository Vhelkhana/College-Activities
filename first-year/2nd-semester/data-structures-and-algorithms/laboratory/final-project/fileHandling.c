#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int rollNo;
    char name[20];
    struct subject
    {
        int sCode;
        char sName;
        int mark;
    } sub[3];
    int total;
    float per;
} student;

// A function that creates a student record

void create()
{
    student *s;
    FILE *fp;
    int n, i, j;

    printf("\nEnter how many students you want: ");
    scanf("%d", &n);

    s = (student*)calloc(n, sizeof(student));
    fp = fopen("mystudents.txt", "w");

    for (i = 0; i < n; i++)
    {
        s[i].total = 0;
        s[i].per = 0;

        printf("\nEnter roll number: ");
        scanf("%d", &s[i]);
        fflush(stdin);
        printf("Enter name: ");
        scanf("%[^\n]s", s[i].name); /* reads a string until user inputs a new line character,
                                        considering the white spaces also as string */
        for (j = 0; j < 3; j++)
        {
            printf("Marks of subject %d: ", j + 1);
            scanf("%d", &s[i].sub[j].mark);
            s[i].total += s[i].sub[j].mark;
        }
        s[i].per = s[i].total / 3.0;
        fwrite(&s[i], sizeof(student), 1, fp);
    }

    fclose(fp);
}

// A function that displays all entries in the record

void display()
{
    student s1;
    FILE *fp;
    int i;

    fp = fopen("mystudents.txt", "r");

    while(fread(&s1, sizeof(student), 1, fp))
    {
        printf("\n%-5d%-20s", s1.rollNo, s1.name);
        for (i = 0; i < 3; i++)
        {
            printf("%4d", s1.sub[i].mark);
        }
        printf("%5d%7.2f", s1.total, s1.per);
    }
    printf("\n");

    fclose(fp);
}

// A function that appends an entry to the record

void append()
{
    student *s;
    FILE *fp;
    int n, i, j;

    printf("\nEnter how many students you want: ");
    scanf("%d", &n);

    s = (student*)calloc(n, sizeof(student));
    fp = fopen("mystudents.txt", "a");

    for (i = 0; i < n; i++)
    {
        s[i].total = 0;
        s[i].per = 0;

        printf("\nEnter roll number: ");
        scanf("%d", &s[i]);
        fflush(stdin);
        printf("Enter name: ");
        scanf("%[^\n]s", s[i].name); /* reads a string until user inputs a new line character,
                                        considering the white spaces also as string */
        for (j = 0; j < 3; j++)
        {
            printf("Marks of subject %d: ", j + 1);
            scanf("%d", &s[i].sub[j].mark);
            s[i].total += s[i].sub[j].mark;
        }
        s[i].per = s[i].total / 3.0;
        fwrite(&s[i], sizeof(student), 1, fp);
    }

    fclose(fp);
}

// A function that determines the number of entries in the record

void noOfRec()
{
    student s1;
    FILE *fp;

    fp = fopen("mystudents.txt", "r");

    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(student);
    printf("\nNO OF RECORDS = %d\n", n);

    fclose(fp);
}

// A function that searches an entry in the record

void search()
{
    student s1;
    FILE *fp;
    int i, rollNo, found = 0;

    fp = fopen("mystudents.txt", "r");

    printf("\nEnter roll no. to search: ");
    scanf("%d", &rollNo);
    while(fread(&s1, sizeof(student), 1, fp))
    {
        if (s1.rollNo == rollNo)
        {
            found = 1;
            printf("\n%-5d%-20s", s1.rollNo, s1.name);
            for (i = 0; i < 3; i++)
            {
                printf("%4d", s1.sub[i].mark);
            }
            printf("%5d%7.2f\n", s1.total, s1.per);
        }
    }
    if (!found)
    {
        printf("\nRecord not found.\n");
    }

    fclose(fp);
}

// A function that updates an entry in the record

void update()
{
    student s1;
    FILE *fp, *fp1;
    int i, rollNo, found = 0;

    fp = fopen("mystudents.txt", "r");
    fp1 = fopen("temp.txt", "w");

    printf("\nEnter roll no. to update: ");
    scanf("%d", &rollNo);
    while(fread(&s1, sizeof(student), 1, fp))
    {
        if (s1.rollNo == rollNo)
        {
            s1.total = 0;
            s1.per = 0;
            found = 1;
            fflush(stdin);
            printf("Enter new name: ");
            scanf("%[^\n]s", s1.name); /* reads a string until user inputs a new line character,
                                            considering the white spaces also as string */
            for (i = 0; i < 3; i++)
            {
                printf("Enter new marks of subject %d: ", i + 1);
                scanf("%d", &s1.sub[i].mark);
                s1.total += s1.sub[i].mark;
            }
            s1.per = s1.total / 3.0;
        }
        fwrite(&s1, sizeof(student), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);

    if (found)
    {
        fp1 = fopen("temp.txt", "r");
        fp = fopen("mystudents.txt", "w");

        while (fread(&s1, sizeof(student), 1, fp1))
        {
            fwrite(&s1, sizeof(student), 1, fp);
        }

        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nRecord not found.\n");
}

// A function that deletes an entry in the record

void delete()
{
    student s1;
    FILE *fp, *fp1;
    int i, rollNo, found = 0;

    fp = fopen("mystudents.txt", "r");
    fp1 = fopen("temp.txt", "w");

    printf("\nEnter roll no. to delete: ");
    scanf("%d", &rollNo);
    while(fread(&s1, sizeof(student), 1, fp))
    {
        if (s1.rollNo == rollNo)
            found = 1;
        else
            fwrite(&s1, sizeof(student), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);

    if (found)
    {
        fp1 = fopen("temp.txt", "r");
        fp = fopen("mystudents.txt", "w");

        while (fread(&s1, sizeof(student), 1, fp1))
        {
            fwrite(&s1, sizeof(student), 1, fp);
        }

        fclose(fp);
        fclose(fp1);
    }
    else
        printf("\nRecord not found.\n");
}

// A function that sorts entries by total in descending order on the screen only

void sortTotalOnScreen()
{
    student *s, s1;
    FILE *fp;
    int i, j;

    fp = fopen("mystudents.txt", "r");

    // Reading size of record

    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(student);
    s = (student*)calloc(n, sizeof(student));
    rewind(fp);
    for (i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(student), 1, fp);
    }

    // Sorting entries

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (s[i].total < s[j].total)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }

    // Printing sorted entries

    for(i = 0; i < n; i++)
    {
        printf("%-5d%-20s", s[i].rollNo, s[i].name);
        for (j = 0; j < 3; j++)
        {
            printf("%4d", s[i].sub[j].mark);
        }
        printf("%5d%7.2f\n", s[i].total, s[i].per);
    }

    fclose(fp);
}

// A function that sorts entries by total in descending order on the file itself

void sortTotalInFile()
{
    student *s, s1;
    FILE *fp;
    int i, j;

    fp = fopen("mystudents.txt", "r");

    // Reading size of record

    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(student);
    s = (student*)calloc(n, sizeof(student));
    rewind(fp);
    for (i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(student), 1, fp);
    }

    fclose(fp);

    // Sorting entries

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (s[i].total < s[j].total)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }

    fopen("mystudents.txt", "w");

    // Printing sorted entries

    for(i = 0; i < n; i++)
    {
        printf("%-5d%-20s", s[i].rollNo, s[i].name);
        for (j = 0; j < 3; j++)
        {
            printf("%4d", s[i].sub[j].mark);
        }
        printf("%5d%7.2f\n", s[i].total, s[i].per);
        fwrite(&s[i], sizeof(student), 1, fp);
    }

    fclose(fp);
}

// A function that sorts the entries by name in ascending order on the screen only

void sortNameOnScreen()
{
    student *s, s1;
    FILE *fp;
    int i, j;

    fp = fopen("mystudents.txt", "r");

    // Reading size of record

    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(student);
    s = (student*)calloc(n, sizeof(student));
    rewind(fp);
    for (i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(student), 1, fp);
    }

    // Sorting entries

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(s[i].name, s[j].name) > 0)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }

    // Printing sorted entries

    for(i = 0; i < n; i++)
    {
        printf("%-5d%-20s", s[i].rollNo, s[i].name);
        for (j = 0; j < 3; j++)
        {
            printf("%4d", s[i].sub[j].mark);
        }
        printf("%5d%7.2f\n", s[i].total, s[i].per);
    }

    fclose(fp);
}

// Main function

int main()
{
    int choice;

    do
    {
        printf("\n1. CREATE");
        printf("\n2. DISPLAY");
        printf("\n3. APPEND");
        printf("\n4. NO OF RECORDS");
        printf("\n5. SEARCH");
        printf("\n6. UPDATE");
        printf("\n7. DELETE");
        printf("\n8. SORT BY TOTAL (DESCENDING - ON SCREEN)");
        printf("\n9. SORT BY TOTAL (DESCENDING - IN FILE)");
        printf("\n10. SORT BY NAME (ON SCREEN)");
        printf("\n0. EXIT");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                append();
                break;
            case 4:
                noOfRec();
                break;
            case 5:
                search();
                break;
            case 6:
                update();
                break;
            case 7:
                delete();
                break;
            case 8:
                sortTotalOnScreen();
                break;
            case 9:
                sortTotalInFile();
                break;
            case 10:
                sortNameOnScreen();
                break;
        }
    }
    while (choice != 0);

    return 0;
}