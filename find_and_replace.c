#include <stdio.h>
#include <string.h>
int main() {
    char a[1000], b[100], c[100], d[1000];
    int i = 0, j = 0, x, y;
    printf("Enter the original text:\n");
    fgets(a, sizeof(a), stdin);
    a[strcspn(a, "\n")] = '\0';
    printf("Enter the word to find:\n");
    fgets(b, sizeof(b), stdin);
    b[strcspn(b, "\n")] = '\0';
    printf("Enter the word to replace with:\n");
    fgets(c, sizeof(c), stdin);
    c[strcspn(c, "\n")] = '\0';
    x = strlen(b);
    y = strlen(c);
    while (a[i] != '\0') {
        if (strncmp(&a[i], b, x) == 0) {
            strcpy(&d[j], c);
            j += y;
            i += x;
        } else {
            d[j++] = a[i++];
        }
    }
    d[j] = '\0';
    printf("\nModified text:\n%s\n", d);
    return 0;
}