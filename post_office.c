#include <stdio.h>
#include <string.h>
struct C {
    char n[50], c[30];
    int p;
};
int main() {
    struct C a[100], t;
    int n;
    printf("Enter number of customers: ");
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        printf("\nName: ");
        fgets(a[i].n, sizeof(a[i].n), stdin);
        a[i].n[strcspn(a[i].n, "\n")] = '\0';
        printf("Category (Differently abled / Senior citizen / Defence personnel / Ordinary): ");
        fgets(a[i].c, sizeof(a[i].c), stdin);
        a[i].c[strcspn(a[i].c, "\n")] = '\0';
        if (strcmp(a[i].c, "Differently abled") == 0)
            a[i].p = 1;
        else if (strcmp(a[i].c, "Senior citizen") == 0)
            a[i].p = 2;
        else if (strcmp(a[i].c, "Defence personnel") == 0)
            a[i].p = 3;
        else
            a[i].p = 4;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].p > a[j].p) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    printf("\nSequence of completion:\n");
    for (int i = 0; i < n; i++)
        printf("%d. %s (%s)\n", i + 1, a[i].n, a[i].c);
    return 0;
}