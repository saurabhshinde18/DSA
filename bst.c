#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char name[100];
    char phone_number[20];
    struct Node *left, *right;
} Node;

Node* createNode(const char *name, const char *phone_number) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone_number, phone_number);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node *root, const char *name, const char *phone_number) {
    if (root == NULL) {
        return createNode(name, phone_number);
    }

    if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name, phone_number);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insert(root->right, name, phone_number);
    }

    return root;
}

Node* search(Node *root, const char *name) {
    if (root == NULL) {
        return NULL;
    }

    int cmp = strcmp(name, root->name);
    if (cmp == 0) {
        return root;
    } else if (cmp < 0) {
        return search(root->left, name);
    } else {
        return search(root->right, name);
    }
}

Node* findMin(Node *root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

void printInOrder(Node *root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("Name: %s, Phone Number: %s\n", root->name, root->phone_number);
        printInOrder(root->right);
    }
}

void trimNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    Node *root = NULL;
    int choice;
    char name[100];
    char phone_number[20];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert contact\n");
        printf("2. Search contact\n");
        printf("3. Print contacts\n");
        printf("4. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                trimNewline(name);
                printf("Enter phone number: ");
                fgets(phone_number, sizeof(phone_number), stdin);
                trimNewline(phone_number);
                root = insert(root, name, phone_number);
                printf("Contact inserted.\n");
                break;
            case 2:
                printf("Enter name to search: ");
                fgets(name, sizeof(name), stdin);
                trimNewline(name);
                Node *result = search(root, name);
                if (result != NULL) {
                    printf("Phone number for %s: %s\n", result->name, result->phone_number);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case 3:
                printf("Contacts in the list:\n");
                printInOrder(root);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}
