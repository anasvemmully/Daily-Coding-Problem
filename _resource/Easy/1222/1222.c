#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int ipt = -1, SUMARRAY[SIZE], SUMARRAYCOUNT[SIZE];
struct node {
    int data, sum;
    struct node *left, *right;
};

void push(int);
int find(int);
void most_frequent_subtree_sum();
int find_subtree_sum(struct node *);
struct node* Node(int);

int main() {

    struct node *head = NULL;

    // define the tree here

    //      5
    //     / \
    //    2  -5
    //  / \  / \
    // 4 -4 2   3

    head = Node(5);
    head->left = Node(2);
    head->right = Node(-5);
    head->right->right = Node(3);
    head->right->left = Node(2);
    head->left->right = Node(-4);
    head->left->left = Node(4);

    find_subtree_sum(head);
    most_frequent_subtree_sum();
    return 0;
} 

struct node* Node(int data) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = temp->sum =  data;
    temp->left = temp->right = NULL;
    return temp;
}

int find_subtree_sum(struct node *tmp) {
    if(tmp == NULL) return 0;

    int left_sum = find_subtree_sum(tmp->left);
    int right_sum = find_subtree_sum(tmp->right);
    tmp->sum += left_sum + right_sum;

    // printf("%d(%d) ", tmp->data, tmp->sum);
    push(tmp->sum);
    return tmp->sum;
    
}

int find(int sum){
    int i, flag = 0;
    for (i = 0; i <= ipt ; i++) {
        if (SUMARRAY[i] == sum) {
            flag = 1;   
            break;
        }
    }
    if (!flag) return -1;
    else return i;
}

void push(int sum){
    int pos = find(sum);
    if (pos != -1) SUMARRAYCOUNT[pos] += 1;
    else {
        SUMARRAYCOUNT[++ipt] = 1;
        SUMARRAY[ipt] = sum;
    }
}

void most_frequent_subtree_sum() {
    int pos = 0;
    for (int i = 1; i <= ipt ; i++) 
    if (SUMARRAYCOUNT[pos] < SUMARRAYCOUNT[i]) pos = i;
    printf("\nmost frequent subtree sum is %d.\n", SUMARRAY[pos]);
}
