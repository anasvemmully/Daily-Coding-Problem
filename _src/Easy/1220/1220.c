#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* generate_tree(int);
struct node* insert(struct node *, int num);
void display(struct node *, int);
void preorder(struct node *);
struct node* merge(struct node *, struct node *);

int main() {

    struct node *t1, *t2;

    
    t1 = generate_tree(1);
    display(t1, 1);
    t2 = generate_tree(2);
    display(t2, 2);

    // merge binary trees
    t1 = merge(t1,t2);
    printf("\nMerged Tree\n*****************");
    display(t1, 1);
    return 0;
}



struct node* merge(struct node *tree1, struct node *tree2) {

    if (!tree1) return tree2;
    if (!tree2) return tree1;
    
    tree1->data += tree2->data;
    tree1->left = merge(tree1->left, tree2->left);
    tree1->right = merge(tree1->right, tree2->right);
    return tree1; 
}

void preorder(struct node *n) {
    
    if (n == NULL) return;
    printf("%d ->", n->data);
    preorder(n->left);
    preorder(n->right);
}

void display(struct node *n, int tree) {
    printf("\n\nDisplaying Tree %d(Pre-Order)\n*********************\n", tree);
    preorder(n);
    printf("\n\n");
}

struct node* insert(struct node *head, int num) {
    struct node *n, *temp;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = num;
    n->left = n->right = NULL;
    if (head == NULL) head = n;
    else {
        temp = head;
        while(temp != NULL) {
            if (temp->data < num) {
                if (temp->right == NULL) {
                    printf("\nInserting @ right");
                    temp->right = n;
                    break;
                } else temp = temp->right;
            } else if (temp->data > num) {
                if (temp->left == NULL) {
                    printf("\nInserting @ left");
                    temp->left = n;
                    break;
                } else temp = temp->left;
            }
        }
    }
    return head;
}

struct node* generate_tree(int tree) {
    printf("\n\nGenerating tree %d ...\n**************************\n", tree);
    struct node *head = NULL;
    int choice, loop = 1, num;
    while(loop) {
        printf("\n1. Insert\n2. Exit\n>>> ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\nEnter the element to insert into tree %d: ", tree);
                scanf("%d", &num);
                head = insert(head, num);
                break;
            case 2:
                loop = 0;
                break;
            default:
                printf("\nEnter a valid option!");
                break;
        }
    }
    return head;
}