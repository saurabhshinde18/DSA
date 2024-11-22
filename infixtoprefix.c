#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '+' || c == '-') 
        return 1;
    if (c == '*' || c == '/') 
        return 2;
    if (c == '^') 
        return 3;
    return 0;
}

void push(char c) {
    if (top < (MAX - 1)) {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void reverse(char* expr) {
    int len = strlen(expr);
    for (int i = 0; i < len / 2; i++) {
        char temp = expr[i];
        expr[i] = expr[len - i - 1];
        expr[len - i - 1] = temp;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int k = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && stack[top] != '(') {
                postfix[k++] = pop();
            }
            pop();
        }
        else if (isOperator(c)) {
            while (!isEmpty() && precedence(stack[top]) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

void infixToPrefix(char* infix, char* prefix) {
    reverse(infix);
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    char postfix[MAX];
    infixToPostfix(infix, postfix);

    reverse(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}

