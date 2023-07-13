#include <stdio.h>
#define N 3
#define M 3

int main() {

    char matrix[N][M] = {
        {'c', 'b', 'a'},
        {'d', 'a', 'f'},
        {'g', 'h', 'i'}
    };
    int cols = 0;

    if (N != 1) {
        for (int i = 0 ; i < M ; i++ ) {
            for (int j = 1 ; j < N ; j++) {
                if (matrix[j - 1] < matrix[j]) {
                    cols++;
                    break;
                }
            }
        }
    }

    printf("\nThe minimum number of columns that can be removed : %d\n", cols);

    return 0;
}