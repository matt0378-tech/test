/*
 * Simple Student Grade Analyzer
 * Demonstrates structs, arrays, functions, loops, and formatted output.
 */

#include <stdio.h>

#define MAX_STUDENTS 5

typedef struct {
    char name[50];
    float grade;
} Student;

float calculate_average(const Student students[], int count)
{
    float total = 0.0f;

    for (int i = 0; i < count; i++) {
        total += students[i].grade;
    }

    return count > 0 ? total / count : 0.0f;
}

const Student *find_top_student(const Student students[], int count)
{
    if (count <= 0) {
        return NULL;
    }

    const Student *top = &students[0];

    for (int i = 1; i < count; i++) {
        if (students[i].grade > top->grade) {
            top = &students[i];
        }
    }

    return top;
}

int main(void)
{
    Student students[MAX_STUDENTS] = {
        {"Alice", 87.5f},
        {"Bob", 92.0f},
        {"Charlie", 78.5f},
        {"Diana", 95.5f},
        {"Eric", 84.0f}
    };

    printf("Student Grade Analyzer\n");
    printf("----------------------\n");

    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("%-10s : %.1f%%\n",
               students[i].name,
               students[i].grade);
    }

    float average = calculate_average(students, MAX_STUDENTS);
    const Student *top = find_top_student(students, MAX_STUDENTS);

    printf("\nClass average: %.1f%%\n", average);

    if (top != NULL) {
        printf("Top student:  %s (%.1f%%)\n",
               top->name,
               top->grade);
    }

    return 0;
}