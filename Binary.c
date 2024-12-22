#include <stdio.h>
#include <string.h>

typedef struct {
    int rollNo;
    char name[50];
    float percentage;
} Student;

void binarySearch(Student students[], int n, int rollNo) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (students[mid].rollNo == rollNo) {
            printf("Student Found: Roll No: %d, Name: %s, Percentage: %.2f\n", 
                   students[mid].rollNo, students[mid].name, students[mid].percentage);
            return;
        } else if (students[mid].rollNo < rollNo) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Student not found\n");
}

int main() {
    Student students[100];
    int n, rollNo;
    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter student details (Roll No, Name, Percentage):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%s%f", &students[i].rollNo, students[i].name, &students[i].percentage);
    }

    printf("Enter Roll No to search: ");
    scanf("%d", &rollNo);

    binarySearch(students, n, rollNo);

    return 0;
}
