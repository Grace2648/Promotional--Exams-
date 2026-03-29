#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct Student {
    char name[50];
    int studentNo;
    int math, english, computer;
};

struct Student students[MAX];
int count = 0;

// Function prototypes
void addStudent();
void viewStudents();
void searchStudent();
void calculateResults();
void saveToFile();
void loadFromFile();
int validateMarks(int marks);
void clearInputBuffer();

int main() {
    int choice;
    loadFromFile(); // Load existing data at startup
    
    while (1) {
        printf("\n=====================================\n");
        printf("     STUDENT MANAGEMENT SYSTEM\n");
        printf("=====================================\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Calculate Results\n");
        printf("5. Save Results to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: calculateResults(); break;
            case 5: saveToFile(); break;
            case 6:
                printf("Program terminated.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int validateMarks(int marks) {
    return marks >= 0 && marks <= 100;
}

void addStudent() {
    if (count >= MAX) {
        printf("Storage full! Cannot add more students.\n");
        return;
    }

    printf("\nEnter Student Name: ");
    clearInputBuffer();
    
    if (fgets(students[count].name, 50, stdin) == NULL) {
        printf("Error reading name!\n");
        return;
    }
    students[count].name[strcspn(students[count].name, "\n")] = 0;

    // Check for duplicate student number
    int tempNo;
    printf("Enter Student Number: ");
    scanf("%d", &tempNo);
    
    for (int i = 0; i < count; i++) {
        if (students[i].studentNo == tempNo) {
            printf("Student number already exists!\n");
            return;
        }
    }
    students[count].studentNo = tempNo;

    // Validate marks
    printf("Math Marks: ");
    scanf("%d", &students[count].math);
    if (!validateMarks(students[count].math)) {
        printf("Invalid marks! Must be between 0-100.\n");
        return;
    }

    printf("English Marks: ");
    scanf("%d", &students[count].english);
    if (!validateMarks(students[count].english)) {
        printf("Invalid marks! Must be between 0-100.\n");
        return;
    }

    printf("Computer Marks: ");
    scanf("%d", &students[count].computer);
    if (!validateMarks(students[count].computer)) {
        printf("Invalid marks! Must be between 0-100.\n");
        return;
    }

    count++;
    printf("Student added successfully!\n");
}

void viewStudents() {
    if (count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n----------------------------------------------------------------\n");
    printf("%-20s %-10s %-6s %-8s %-8s\n", "Name", "StudentNo", "Math", "English", "Computer");
    printf("----------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-6d %-8d %-8d\n",
               students[i].name,
               students[i].studentNo,
               students[i].math,
               students[i].english,
               students[i].computer);
    }
}

void searchStudent() {
    int number, found = 0;
    printf("Enter Student Number: ");
    scanf("%d", &number);

    for (int i = 0; i < count; i++) {
        if (students[i].studentNo == number) {
            printf("\n=== Student Found ===\n");
            printf("Name: %s\n", students[i].name);
            printf("Student No: %d\n", students[i].studentNo);
            printf("Math: %d\n", students[i].math);
            printf("English: %d\n", students[i].english);
            printf("Computer: %d\n", students[i].computer);
            
            // Show calculated results
            int total = students[i].math + students[i].english + students[i].computer;
            float average = total / 3.0;
            char grade;
            if (average >= 80) grade = 'A';
            else if (average >= 70) grade = 'B';
            else if (average >= 60) grade = 'C';
            else if (average >= 50) grade = 'D';
            else grade = 'F';
            
            printf("Total: %d\n", total);
            printf("Average: %.2f\n", average);
            printf("Grade: %c\n", grade);
            
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

void calculateResults() {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    printf("\n=== Student Results ===\n");
    for (int i = 0; i < count; i++) {
        int total = students[i].math + students[i].english + students[i].computer;
        float average = total / 3.0;
        char grade;

        if (average >= 80) grade = 'A';
        else if (average >= 70) grade = 'B';
        else if (average >= 60) grade = 'C';
        else if (average >= 50) grade = 'D';
        else grade = 'F';

        printf("\nStudent: %s (No: %d)\n", students[i].name, students[i].studentNo);
        printf("Marks - Math: %d, English: %d, Computer: %d\n", 
               students[i].math, students[i].english, students[i].computer);
        printf("Total: %d\n", total);
        printf("Average: %.2f\n", average);
        printf("Grade: %c\n", grade);
        printf("Status: %s\n", grade != 'F' ? "PASS" : "FAIL");
    }
}

void saveToFile() {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%-20s %-10s %-6s %-8s %-8s\n", 
            "Name", "StudentNo", "Math", "English", "Computer");
    fprintf(file, "---------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        fprintf(file, "%-20s %-10d %-6d %-8d %-8d\n",
                students[i].name,
                students[i].studentNo,
                students[i].math,
                students[i].english,
                students[i].computer);
    }

    fclose(file);
    printf("Data saved to students.txt successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        return; // File doesn't exist yet
    }

    char buffer[256];
    fgets(buffer, 256, file); // Skip header
    fgets(buffer, 256, file); // Skip separator line

    count = 0;
    while (fscanf(file, "%49s %d %d %d %d\n",
                  students[count].name,
                  &students[count].studentNo,
                  &students[count].math,
                  &students[count].english,
                  &students[count].computer) == 5 && count < MAX) {
        count++;
    }

    fclose(file);
    printf("Loaded %d student records from file.\n", count);
}
