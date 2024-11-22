#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
typedef struct {
    int ticketId;
    char description[100];
} Ticket;
typedef struct {
    Ticket queue[MAX];
    int front, rear;
} CircularQueue;
void initializeQueue(CircularQueue *q);
int isFull(CircularQueue *q);
int isEmpty(CircularQueue *q);
void enqueue(CircularQueue *q, Ticket t);
Ticket dequeue(CircularQueue *q);
void displayQueue(CircularQueue *q);
void generateTicketId(CircularQueue *q, int *ticketCounter);
int main() {
    CircularQueue q;
    Ticket t;
    int choice;
    int ticketCounter = 1;
    initializeQueue(&q);
    while (1) {
        printf("\nCustomer Support Ticket Management System\n");
        printf("1. Submit a ticket\n");
        printf("2. Process a ticket\n");
        printf("3. Display queue status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (isFull(&q)) {
                    printf("Queue is full! Cannot accept new tickets.\n");
                } else {
                    generateTicketId(&q, &ticketCounter);
                    t.ticketId = ticketCounter;
                    printf("Enter issue description: ");
                    getchar();
                    fgets(t.description, sizeof(t.description), stdin);
                    t.description[strcspn(t.description, "\n")] = 0;

                    enqueue(&q, t);
                    printf("Ticket submitted successfully with ID %d\n", t.ticketId);
                }
                break;
            case 2:
                if (isEmpty(&q)) {
                    printf("No tickets to process.\n");
                } else {
                    t = dequeue(&q);
                    printf("Ticket ID %d processed. Description: %s\n", t.ticketId, t.description);
                }
                break;
           case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void initializeQueue(CircularQueue *q) {
    q->front = q->rear = -1;
}

int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}

int isEmpty(CircularQueue *q) {
    return q->front == -1;
}

void enqueue(CircularQueue *q, Ticket t) {
    if (isFull(q)) {
        printf("Queue is full! Cannot accept new tickets.\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX;
    q->queue[q->rear] = t;
}

Ticket dequeue(CircularQueue *q) {
    Ticket t = {-1, ""};
    if (isEmpty(q)) {
        printf("Queue is empty! No tickets to process.\n");
        return t;
    }

    t = q->queue[q->front];

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    return t;
}

void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. No tickets to display.\n");
        return;
    }

    printf("\nCurrent tickets in the queue:\n");
    int i = q->front;
    while (i != q->rear) {
        printf("Ticket ID: %d, Description: %s\n", q->queue[i].ticketId, q->queue[i].description);
        i = (i + 1) % MAX;
    }
    printf("Ticket ID: %d, Description: %s\n", q->queue[i].ticketId, q->queue[i].description);
}

void generateTicketId(CircularQueue *q, int *ticketCounter) {
    (*ticketCounter)++;
}
