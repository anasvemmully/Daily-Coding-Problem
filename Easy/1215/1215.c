#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// Try running ./a.out <number>
// compile the file like, cc 1215.c -lm 
// if you are using linux

int main(int argc, char *argv[]) {
    
    int i, flag = 0, num = atoi(argv[1]), steps = 0;
    while(num > 1) {
        for (i = (int)sqrt(num), flag = 0; i >= 2; i--) {
            if (num % i == 0) {
                flag = 1;
                break;
            }
        }
        if (flag) num = num/i;
        else num = num -1;
        steps++; 
    }
    printf("\nNumber of steps required : %d\n", steps);

    return 0;
}