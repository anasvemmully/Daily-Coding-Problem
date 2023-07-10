#include <stdio.h>
#define N 10

int STACK[N], QUEUE[N];
int top = -1, f = -1, r = -1;

void enqueue(int);
int dequeue();
void push(int);
int pop();

void display_q() {
    for (int k = f; f <= r ; f++) printf("\n%d. %d", k, QUEUE[k]);
}

int main() {

    // Enter upto 10 elements here
    int nums[] = {1,2,3,4,5,6,7,8,9};
    int limit, i, j, length = (int) sizeof(nums)/4;

    for (i = 0; i < length ; i++) push(nums[i]);
    
    printf("\nStack Before : ");
    for (i = top; i >= 0  ; i--) printf("\n%d. %d", i, STACK[i]);
    
    // reversing operation is done here
    for (i = length - 1, limit = 0; i > limit; i--) {
        for (j = i ; j > 0; j--) enqueue(pop());
        for (j = i ; j > 0; j--) push(dequeue());
        limit++;
    }

    printf("\n\nStack After : ");
    for (i = top; i >= 0  ; i--) printf("\n%d. %d", i, STACK[i]);
    printf("\n");
    
    return 0;
}

void enqueue(int data){
    if (f == N) printf("\nOverflow!");
    else {
        if (f == -1 && r == -1) r = 0;
        QUEUE[++f] = data;
    }
}

int dequeue(){
    int temp;
    temp = QUEUE[r];
    if (f == -1 && r == -1) printf("\nUnderflow!");
    else if (f==r) f = r = -1;
    else r++;
    return temp;
}

void push(int data){
    if (top == N) printf("\nOverflow!");
    else STACK[++top] = data;
}

int pop(){
    if (top == -1) printf("\nUnderflow!");
    else {
        return STACK[top--];
    }
}

