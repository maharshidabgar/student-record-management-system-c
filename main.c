#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    int age;
    char course[50];
    float marks;
};

void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
int rollExists(int roll);

int main() {
    int choice;

    while (1) {
        printf("\n========== STUDENT RECORD MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

int rollExists(int roll) {
    FILE *fp;
    struct Student s;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        return 0;
    }

    while (fscanf(fp, "%d|%49[^|]|%d|%49[^|]|%f\n",
                  &s.roll, s.name, &s.age, s.course, &s.marks) == 5) {
        if (s.roll == roll) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

void addStudent() {
    FILE *fp;
    struct Student s;

    fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll);

    if (rollExists(s.roll)) {
        printf("Roll number already exists! Please use a unique roll number.\n");
        fclose(fp);
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Age: ");
    scanf("%d", &s.age);

    printf("Enter Course: ");
    scanf(" %[^\n]", s.course);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fprintf(fp, "%d|%s|%d|%s|%.2f\n", s.roll, s.name, s.age, s.course, s.marks);
    fclose(fp);

    printf("Student record added successfully!\n");
}

void viewStudents() {
    FILE *fp;
    struct Student s;
    int found = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n===================== STUDENT RECORDS =====================\n");
    printf("%-10s %-20s %-8s %-20s %-8s\n", "Roll", "Name", "Age", "Course", "Marks");
    printf("------------------------------------------------------------\n");

    while (fscanf(fp, "%d|%49[^|]|%d|%49[^|]|%f\n",
                  &s.roll, s.name, &s.age, s.course, &s.marks) == 5) {
        printf("%-10d %-20s %-8d %-20s %-8.2f\n",
               s.roll, s.name, s.age, s.course, s.marks);
        found = 1;
    }

    if (!found) {
        printf("No student records available.\n");
    }

    fclose(fp);
}

void searchStudent() {
    FILE *fp;
    struct Student s;
    int roll, found = 0;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    while (fscanf(fp, "%d|%49[^|]|%d|%49[^|]|%f\n",
                  &s.roll, s.name, &s.age, s.course, &s.marks) == 5) {
        if (s.roll == roll) {
            printf("\nStudent Found:\n");
            printf("Roll Number : %d\n", s.roll);
            printf("Name        : %s\n", s.name);
            printf("Age         : %d\n", s.age);
            printf("Course      : %s\n", s.course);
            printf("Marks       : %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", roll);
    }

    fclose(fp);
}

void updateStudent() {
    FILE *fp, *temp;
    struct Student s;
    int roll, found = 0;

    fp = fopen("students.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    while (fscanf(fp, "%d|%49[^|]|%d|%49[^|]|%f\n",
                  &s.roll, s.name, &s.age, s.course, &s.marks) == 5) {
        if (s.roll == roll) {
            found = 1;

            printf("Enter New Name: ");
            scanf(" %[^\n]", s.name);

            printf("Enter New Age: ");
            scanf("%d", &s.age);

            printf("Enter New Course: ");
            scanf(" %[^\n]", s.course);

            printf("Enter New Marks: ");
            scanf("%f", &s.marks);
        }

        fprintf(temp, "%d|%s|%d|%s|%.2f\n", s.roll, s.name, s.age, s.course, s.marks);
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("Student record updated successfully!\n");
    else
        printf("Student with roll number %d not found.\n", roll);
}

void deleteStudent() {
    FILE *fp, *temp;
    struct Student s;
    int roll, found = 0;

    fp = fopen("students.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    while (fscanf(fp, "%d|%49[^|]|%d|%49[^|]|%f\n",
                  &s.roll, s.name, &s.age, s.course, &s.marks) == 5) {
        if (s.roll == roll) {
            found = 1;
            continue;
        }

        fprintf(temp, "%d|%s|%d|%s|%.2f\n", s.roll, s.name, s.age, s.course, s.marks);
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("Student record deleted successfully!\n");
    else
        printf("Student with roll number %d not found.\n", roll);
}