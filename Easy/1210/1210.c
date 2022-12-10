#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
}*head = NULL;

int num, f = -1, c = -1;

void insert(int);
void traverse(struct node *, int);
void find(struct node *, int);

int main() {

    //     5
    //    / \
    //   3   9
    //  / \ / \
    // 1  4 7 10

    insert(5);
    insert(3);
    insert(9);
    insert(1);
    insert(4);
    insert(7);
    insert(10);

    printf("\nEnter the number to find the floor and ceiling of the given integer : \n");
    scanf("%d", &num);

    // traverse(head, num);
    find(head, num);
    printf("\nFloor and ceil for %d is %d and %d", num, f, c);

    printf("\n\n");

    return 0;
}

void find(struct node *n, int num) {
    while(n) {
        if (n->data == num)
        {
            f = n->data;
            c = n->data;
            break;
        } else if (num < n->data)
        {
            c = n->data;
            n = n->left;
        } else {
            f = n->data;
            n = n->right;
        }
    }
}

void traverse(struct node *n, int num) {
    if (n == NULL) return;
    traverse(n->left, num);
    traverse(n->right, num);
    printf("%d-> ", n->data); 

}

void insert(int data) {

    struct node *NODE = NULL, *temp;
    NODE = (struct node *)malloc(sizeof(struct node));
    NODE->data = data;
    NODE->left = NODE->right = NULL;

    if (head == NULL) head = NODE;
    else {
        temp = head;
        while (temp != NULL) {
            if (data > temp->data) {
                if (temp->right == NULL) {
                    temp->right = NODE;
                    break;
                }
                temp = temp->right;
            } else if (data < temp->data) {
                if (temp->left == NULL) {
                    temp->left = NODE;
                    break;
                }
                temp = temp->left;
            }
        }
    }

}