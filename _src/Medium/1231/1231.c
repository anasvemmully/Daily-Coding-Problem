#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double get_random();

int main() {

    int in_circle = 0, in_square = 0;
    double res, x, y, pi;

    for (int i = 0; i < 1000000; i++) {
        x = get_random();
        y = get_random();

        res = x*x + y*y;
        // printf("\nres : %lf", res);
        if (res <= 1) in_circle++;
        else in_square++;
    }

    pi = 4*( (double)in_circle / (in_square + in_circle));
    printf("\npi: %lf\n", pi);

    return 0;
}

double get_random() {
    return (double)(rand()%100000)/100000;
}