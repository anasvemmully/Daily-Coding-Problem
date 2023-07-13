#include <stdio.h>
#include <stdlib.h>

// Try running ./a.out <number>

int main(int argc, char *argv[]) {

    int num = atoi(argv[1]);

    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    printf("\nsetbit count : %d\n", count);

    return 0;
}