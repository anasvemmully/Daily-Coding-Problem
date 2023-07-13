#include<stdio.h>
#include<stdlib.h>

struct node {
    int data, is_unival_subtree;
    struct node *left, *right;
}*head = NULL;

struct node * Node(int); 
int postorder(struct node *);
int is_univalsubtree(struct node *);


int main() {

    //   0
    //  / \
    // 1   0
    //    / \
    //   1   0
    //  / \
    // 1   1
    
    head = Node(0);
    head->left = Node(1);
    head->right = Node(0);
    head->right->left = Node(1);
    head->right->right = Node(0);
    head->right->left->left = Node(1);
    head->right->left->right = Node(1);
    
    int count = postorder(head);
    printf("\nnumber of unival subtrees : %d", count);
    printf("\n\n");
    return 0;
}

int is_univalsubtree(struct node *root) {
    if (!root) return 1;
    if (root->left != NULL && root->data != root->left->data) return 0;
    if (root->right != NULL && root->data != root->right->data) return 0;
    return is_univalsubtree(root->left) && is_univalsubtree(root->right);
}

int postorder(struct node *n) {
    if (n == NULL) return 0;
    int left = postorder(n->left);
    int right = postorder(n->right);
    n->is_unival_subtree = is_univalsubtree(n);
    return left + right + n->is_unival_subtree;
    
}

struct node * Node(int data) {
    struct node *tmp = NULL;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->is_unival_subtree = 0;
    tmp->left = tmp->right = NULL;
    return tmp;
}