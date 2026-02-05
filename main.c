#include <stdio.h>
#include <string.h>

// Define a union for different types of marks
union Marks {
    int math;
    int science;
    int english;
};

// Define a structure for Student
struct Student {
    int id;
    char name[50];
    int age;
    union Marks marks;
};

int main() {
    struct Student students[100];
    int n, choice;
    
    printf("=== Student Record Management System ===\n");
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input student details
    for(int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i+1);
        students[i].id = i + 1;
        printf("Enter Name: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Enter Age: ");
        scanf("%d", &students[i].age);
        printf("Enter Math Marks: ");
        scanf("%d", &students[i].marks.math);
    }

    // Menu
    do {
        printf("\n--- Menu ---\n");
        printf("1. Display All Students\n");
        printf("2. Display Specific Student by ID\n");
        printf("3. Update Student Marks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n--- All Students ---\n");
                for(int i = 0; i < n; i++) {
                    printf("ID: %d\nName: %s\nAge: %d\nMath Marks: %d\n\n",
                        students[i].id, students[i].name, students[i].age, students[i].marks.math);
                }
                break;

            case 2:
                {
                    int id;
                    printf("Enter Student ID to display: ");
                    scanf("%d", &id);
                    if(id > 0 && id <= n) {
                        struct Student s = students[id-1];
                        printf("\nID: %d\nName: %s\nAge: %d\nMath Marks: %d\n",
                            s.id, s.name, s.age, s.marks.math);
                    } else {
                        printf("❌ Invalid ID\n");
                    }
                }
                break;

            case 3:
                {
                    int id;
                    printf("Enter Student ID to update marks: ");
                    scanf("%d", &id);
                    if(id > 0 && id <= n) {
                        printf("Enter new Math Marks: ");
                        scanf("%d", &students[id-1].marks.math);
                        printf("✅ Marks updated successfully!\n");
                    } else {
                        printf("❌ Invalid ID\n");
                    }
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("❌ Invalid choice. Try again.\n");
        }

    } while(choice != 4);

    return 0;
}
