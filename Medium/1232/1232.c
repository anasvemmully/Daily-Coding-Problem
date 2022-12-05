#include<stdio.h>
#include<stdlib.h>

#define ROW 4
#define COLUMN 6

int main() {

    int i,j, number_of_regions = 0;
    // char matrix[ROW][COLUMN] = {
    //     {'\\',' ',' ',' ',' ','/'},
    //     {' ','\\',' ',' ','/',' '},
    //     {' ',' ','\\','/',' ',' '}
    // };

    char matrix[ROW][COLUMN] = {
        {'\\',' ',' ',' ','\\',' '},
        {' ','\\',' ',' ','/',' '},
        {' ',' ','\\','/','\\','/'},
        {' ',' ','/',' ',' ',' '}
    };

    printf("\nGiven matrix contains: \n");
    for (i = 0; i < ROW; i++) printf("--");
    printf("\n");
    for (i = 0; i < ROW; i++){
        printf("|");
        for ( j= 0; j < COLUMN ; j++) 
        {
            printf("%c", matrix[i][j]);
        }
        printf("|\n");
    }
    for (i = 0; i < ROW; i++) printf("--");
    printf("\n");

    // logic for finding the regions inside the given matrix
    for( i=0; i<ROW ; i++ ){
        for( j=0; j<COLUMN ; j++ ){
            
            if (j == COLUMN - 1) {
                if (matrix[i][j] == '/' || matrix[i][j] == '\\') {
                    number_of_regions+=2;
                }
            } else if (i != 0) {
                if (matrix[i][j] == '\\') {
                    if (j > 1) {
                        if ( !(matrix[i-1][j-1] == '\\' || matrix[i-1][j] == '/') ) {
                            number_of_regions--;
                        }
                    }
                } else if (matrix[i][j] == '/') {
                    if (j > 1) {
                        if ( !(matrix[i-1][j+1] == '/' || matrix[i-1][j] == '\\') ) {
                            number_of_regions--;
                        }
                    }
                }
            } else {
                if (matrix[i][j] == '\\' || matrix[i][j] == '/') number_of_regions++;
            }
        }
    }

    printf("\nThe number of regions in the given matrix is %d\n\n", number_of_regions);

    return 0;
}