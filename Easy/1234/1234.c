#include <stdio.h> 

int main(int argc , char *argv[] ) {  

    int i, R, G, B;
    R = G = B = 0;
    
    char QUX[] = {'R', 'G', 'B', 'G', 'R'};
    int length = sizeof(QUX);

    for (i = 0 ; i < length ; i++ ) {
        if (i == 0) printf("\nQUX : ");
        printf("%c ", QUX[i]);
        
        if (QUX[i] == 'R') R++;
        else if (QUX[i] == 'G') G++;
        else if (QUX[i] == 'B') B++;

    }

    if (length > 0) {
        printf("\nThe smallest length : ");
        if ( R == length || B == length || G == length ) printf("%d\n", length);
        else if ( R%2 == B%2 && R%2 == G%2 && G%2 == B%2 ) printf("%d\n", 2);
        else printf("%d\n", 1);
    }

    return 0;
}
