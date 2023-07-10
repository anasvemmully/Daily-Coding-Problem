#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
} *head = NULL;
int min, max;
void insert(int);
int postorder(struct node *);

int main()
{

    // define your BST here
    //     5
    //    / \
    //   3   8
    //  / \ / \
    // 2  4 6  10

    int sum;

    printf("\nEnter the range : \n");
    scanf("%d%d", &min, &max);

    insert(5);
    insert(3);
    insert(8);
    insert(2);
    insert(4);
    insert(6);
    insert(10);

    sum = postorder(head);
    printf("\nSum of the elements in the range [%d, %d] is %d\n", min, max, sum);
    return 0;
}

int postorder(struct node *n) {
    if (n == NULL) return 0;
    int left_sum = postorder(n->left);
    int right_sum = postorder(n->right);
    if (n->data == min || (n->data > min && n->data < max) || n->data == max) return left_sum +right_sum + n->data ;
    else return left_sum + right_sum;
}

void insert(int data)
{
    struct node *NODE = NULL, *tmp;
    NODE = (struct node *)malloc(sizeof(struct node));
    NODE->data = data;
    NODE->left = NODE->right = NULL;

    if (head == NULL) head = NODE;
    else {
        tmp = head;
        while (tmp != NULL) {
            if (tmp ->data > data) {
                if (tmp->left == NULL) {
                    tmp->left = NODE;
                    break;
                }
                tmp = tmp->left;
            }
            else if (tmp->data < data) {
                if (tmp->right == NULL) {
                    tmp->right = NODE; 
                    break;
                }
                tmp = tmp->right;
            }
        }
    }

}
