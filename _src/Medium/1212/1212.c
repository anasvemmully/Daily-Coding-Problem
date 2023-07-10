#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int size;
bool *b;

bool* init(int);
void set(int, int);
int get(int);

// implementing a bit array
int main() {
    int choice, val, i;
    printf("\nEnter the size for the bit array  : ");
    scanf("%d", &size);
    
    b = init(size);
    printf("\nSize of the bitarray is %ld\n", size*sizeof(*b));

    while (1) {
        printf("\n1. set\n2. get\n3. exit\n>>> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the `i` and val to be set : ");
            scanf("%d%d", &i, &val);
            set(i, val);
            break;
        case 2:
            printf("\nEnter the `i` to get : ");
            scanf("%d", &i);
            if (get(i) != -1) printf("val : %d", get(i));
            else printf("\nError!"); 
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\nTry a valid option!");
            break;
        }
        printf("\n\n");
    }
    return 0;
}

int get(int i) {
    if (i <= size) 
        // return *(b+(i-1));
        return (b[i-1]);
    else
        return -1; 
}

void set(int i , int val) {
    if (i <= size) 
    *(b+(i-1)) = val;
    else printf("\nError!"); 
}

bool* init(int size) {
    return (bool*)malloc(size * sizeof(bool));    
}

