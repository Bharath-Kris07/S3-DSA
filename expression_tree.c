#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_EXPR_SIZE 100
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};
char charStack[MAX_EXPR_SIZE];
int charTop = -1;
void pushChar(char item) {
    charStack[++charTop] = item;
}
char popChar() {
    if (charTop == -1) return -1;
    return charStack[charTop--];
}
char peekChar() {
    return charStack[charTop];
}
struct Node* nodeStack[MAX_EXPR_SIZE];
int nodeTop = -1;
void pushNode(struct Node* node) {
    nodeStack[++nodeTop] = node;
}
struct Node* popNode() {
    if (nodeTop == -1) return NULL;
    return nodeStack[nodeTop--];
}
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) {
        printf("Memory allocation error\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
void infixToPostfix(const char* infix, char* postfix) {
    int i, j;
    charTop = -1;
    for (i = 0, j = 0; infix[i]; ++i) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            pushChar(infix[i]);
        } else if (infix[i] == ')') {
            while (charTop != -1 && peekChar() != '(') {
                postfix[j++] = popChar();
            }
            popChar();
        } else if (isOperator(infix[i])) {
            while (charTop != -1 && precedence(infix[i]) <= precedence(peekChar())) {
                postfix[j++] = popChar();
            }
            pushChar(infix[i]);
        }
    }
    while (charTop != -1) {
        postfix[j++] = popChar();
    }
    postfix[j] = '\0';
}
struct Node* constructTree(const char* postfix) {
    struct Node *t, *t1, *t2;
    nodeTop = -1;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            t = newNode(postfix[i]);
            pushNode(t);
        } else if (isOperator(postfix[i])) {
            t = newNode(postfix[i]);
            t1 = popNode();
            t2 = popNode();
            t->right = t1;
            t->left = t2;
            pushNode(t);
        }
    }
    t = popNode();
    return t;
}
void printPrefix(struct Node* root) {
    if (root) {
        printf("%c", root->data);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}
void printPostfix(struct Node* root) {
    if (root) {
        printPostfix(root->left);
        printPostfix(root->right);
        printf("%c", root->data);
    }
}
int main() {
    char infix[MAX_EXPR_SIZE];
    char postfix[MAX_EXPR_SIZE];
    printf("Enter a simple arithmetic infix expression (e.g., (a+b)*(c-d)):\n");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("\nIntermediate Postfix Expression: %s\n", postfix);
    struct Node* root = constructTree(postfix);
    printf("Expression Tree has been constructed.\n\n");
    printf("Prefix Equivalent (from tree traversal): ");
    printPrefix(root);
    printf("\n");
    printf("Postfix Equivalent (from tree traversal): ");
    printPostfix(root);
    printf("\n");
    return 0;
}