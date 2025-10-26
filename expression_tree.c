#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_EXPR_SIZE 100
struct Node {
    char data[MAX_EXPR_SIZE]; // Changed from char to char array
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
    strcpy(node->data, data); // Use strcpy to copy the token
    node->left = NULL;
    node->right = NULL;
    return node;
}
int precedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
    }
    return -1;
}
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
void infixToPostfix(const char* infix, char* postfix) {
    int i = 0, j = 0;
    charTop = -1;
    char tempToken[MAX_EXPR_SIZE];

    while (infix[i] != '\0') {
        if (isspace(infix[i])) {
            i++;
            continue;
        }
                if (isalnum(infix[i])) {
            int k = 0;

            while (isalnum(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; 
        }

        else if (infix[i] == '(') {
            pushChar(infix[i++]);
        }
    
        else if (infix[i] == ')') {
            while (charTop != -1 && peekChar() != '(') {
                postfix[j++] = popChar();
                postfix[j++] = ' '; 
            }
            popChar(); 
            i++;
        }
        else if (isOperator(infix[i])) {
            char currOp = infix[i];
            while (charTop != -1 && peekChar() != '(' &&
                   (precedence(peekChar()) > precedence(currOp) ||
                   (precedence(peekChar()) == precedence(currOp) && currOp != '^')))
            {
                postfix[j++] = popChar();
                postfix[j++] = ' '; 
            }
            pushChar(currOp);
            i++;
        }
        else {
            i++;
        }
    }
    while (charTop != -1) {
        postfix[j++] = popChar();
        postfix[j++] = 
    }
    
    if (j > 0) j--;
    postfix[j] = '\0'; 
}
struct Node* constructTree(const char* postfix) {
    struct Node *t, *t1, *t2;
    nodeTop = -1;
    char postfixCopy[MAX_EXPR_SIZE];
    strcpy(postfixCopy, postfix);
    char* token = strtok(postfixCopy, " ");
    while (token != NULL) {
        if (isOperator(token[0]) && token[1] == '\0') {
            t = newNode(token);
            t1 = popNode();
            t2 = popNode();
            t->right = t1;
            t->left = t2;
            pushNode(t);
        }
        else if (isalnum(token[0])) {
            t = newNode(token);
            pushNode(t);
        }
        token = strtok(NULL, " ");
    }
    t = popNode();
    return t;
}
void printPrefix(struct Node* root) {
    if (root) {
        printf("%s ", root->data); // Print string with a space
        printPrefix(root->left);
        printPrefix(root->right);
    }
}
void printPostfix(struct Node* root) {
    if (root) {
        printPostfix(root->left);
        printPostfix(root->right);
        printf("%s ", root->data); // Print string with a space
    }
}
int main() {
    char infix[MAX_EXPR_SIZE];
    char postfix[MAX_EXPR_SIZE];
    
    printf("Enter an arithmetic infix expression (e.g., (12 + 5) * (30 - 4)):\n");
    
    // Use fgets to read the whole line, including spaces
    if (fgets(infix, sizeof(infix), stdin) == NULL) {
         printf("Error reading input.\n");
         return 1;
    }
    // Remove the newline character that fgets adds
    infix[strcspn(infix, "\n")] = 0;

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