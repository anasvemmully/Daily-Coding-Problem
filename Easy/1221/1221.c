#include <stdio.h>

int fib(int);

int main() {
    int num;
    printf("\nEnter the number : ");
    scanf("%d", &num);
    printf("%dth fibinocci number: %d\n", num, fib(num));
    return 0;
}

int fib(int num) {
    if (num < 2) return 0; 
    else if (num == 2) return 1;
    else return fib(num-1) + fib(num-2);
}
