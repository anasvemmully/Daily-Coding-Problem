#include <stdio.h>
#define MAX_LIMIT 10

int main() {

    char string[MAX_LIMIT];
    int open = 0, close = 0;
    printf("\nEnter the expression : ");
    fgets(string, MAX_LIMIT, stdin);

    for (int i = 0; i != '\n' ; i++) {
        if (string[i] == '(') open++;
        else if (string[i] == ')') close++;
    }
    printf("\nMinimum number of parentheses to be removed is %d\n", ((open - close) < 0) ? close-open : open-close);

    return 0;
}