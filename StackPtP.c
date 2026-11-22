#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

// PUSH operation
void push(char item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    }
    else {
        stack[++top] = item;
    }
}

// POP operation
char pop() {
    if (top == -1) {
        return '\0';
    }

    return stack[top--];
}

// Check precedence
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    if (op == '^')
        return 3;

    return 0;
}

// Infix to Postfix
void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum((unsigned char)ch)) {
            postfix[j++] = ch;
        }

        else if (ch == '(') {
            push(ch);
        }

        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top != -1)
                pop();
        }

        else {
            while (top != -1 &&
                  stack[top] != '(' &&
                  (precedence(stack[top]) > precedence(ch) ||
                  (precedence(stack[top]) == precedence(ch) &&
                   ch != '^'))) {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression = %s\n", postfix);
}

// Main function
int main() {
    char infix[MAX];

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    infixToPostfix(infix);

    return 0;
}
