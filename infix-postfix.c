#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100
char opstack[MAX];
int opTop = -1;
char postfix[MAX][MAX]; 
int postIndex = 0;
void push(char op) {
    opstack[++opTop] = op;
}
char pop() {
    return opstack[opTop--];
}
char peek() {
    return opstack[opTop];
}
int isEmpty() {
    return opTop == -1;
}
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
int isRightAssociative(char op) {
    return op == '^';
}
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
void infixToPostfix(char infix[]) {
    int i = 0, k;
    char token[MAX];
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            k = 0;
            while (isalnum(infix[i])) {
                token[k++] = infix[i++];
            }
            token[k] = '\0';
            strcpy(postfix[postIndex++], token);
        } else if (infix[i] == '(') {
            push(infix[i++]);
        } else if (infix[i] == ')') {
            while (!isEmpty() && peek() != '(') {
                token[0] = pop(); token[1] = '\0';
                strcpy(postfix[postIndex++], token);
            }
            if (!isEmpty() && peek() == '(') pop(); 
            i++;
        } else if (isOperator(infix[i])) {
            char currOp = infix[i];
            while (!isEmpty() &&
                   (precedence(peek()) > precedence(currOp) ||
                    (!isRightAssociative(currOp) && precedence(peek()) == precedence(currOp)))) {
                token[0] = pop(); token[1] = '\0';
                strcpy(postfix[postIndex++], token);
            }
            push(currOp);
            i++;
        } else {
            i++; 
        }
    }
    while (!isEmpty()) {
        token[0] = pop(); token[1] = '\0';
        strcpy(postfix[postIndex++], token);
    }
}
int evalPostfix() {
    int stack[MAX];
    int top = -1;
    int a, b;
    for (int i = 0; i < postIndex; i++) {
        if (isdigit(postfix[i][0])) {
            stack[++top] = atoi(postfix[i]);
        } else if (isalpha(postfix[i][0])) {
            int val;
            printf("Enter value for %s: ", postfix[i]);
            scanf("%d", &val);
            stack[++top] = val;
        } else {
            b = stack[top--];
            a = stack[top--];
            switch (postfix[i][0]) {
                case '+': stack[++top] = a + b; break;
                case '-': stack[++top] = a - b; break;
                case '*': stack[++top] = a * b; break;
                case '/': stack[++top] = a / b; break;
                case '^': stack[++top] = (int)pow(a, b); break;
            }
        }
    }
    return stack[top];
}
int main() {
    char infixExp[MAX];
    printf("Enter infix expression (e.g. A+4*B-6): ");
    fgets(infixExp, sizeof(infixExp), stdin);
    infixExp[strcspn(infixExp, "\n")] = '\0'; 
    infixToPostfix(infixExp);
    printf("Postfix Expression: ");
    for (int i = 0; i < postIndex; i++) {
        printf("%s ", postfix[i]);
    }
    int result = evalPostfix();
    printf("\nResult: %d\n", result);
    return 0;
}