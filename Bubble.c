#include <stdio.h>

typedef struct {
    int rollNo;
    char name[50];
    float percentage;
} Student;

void bubbleSort(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].percentage < students[j + 1].percentage) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    Student students[100];
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter student details (Roll No, Name, Percentage):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%s%f", &students[i].rollNo, students[i].name, &students[i].percentage);
    }

    bubbleSort(students, n);

    printf("Top 10 Toppers:\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%d %s %.2f\n", students[i].rollNo, students[i].name, students[i].percentage);
    }

    return 0;
}
