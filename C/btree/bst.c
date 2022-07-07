#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

t_btree *bstree_create_node(int item) {
    t_btree *node = malloc(sizeof(t_btree));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int comparator(int a, int b) {
    if (a > b) {
        return 1;
    } else {
        return 0;
    }
}

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    t_btree *curr = root;
    while ((root->left != NULL) || (root->right != NULL)) {
        if (curr->item == item) {
            printf("ERROR: node exists");
            return;
        }

        if (cmpf(item, curr->item) == 1) {
            if (curr->right == NULL) {
                curr->right = bstree_create_node(item);
                return;
            } else {
                curr = curr->right;
            }
        } else {
            if (curr->left == NULL) {
                curr->left = bstree_create_node(item);
                return;
            } else {
                curr = curr->left;
            }
        }
    }
    return;
}

void leaf_print(int item) {
    printf("%d ", item);
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root == NULL) {
        return;
    }
    bstree_apply_infix(root->left, applyf);
    applyf(root->item);
    bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (root == NULL) {
        return;
    }
    applyf(root->item);
    bstree_apply_prefix(root->left, applyf);
    bstree_apply_prefix(root->right, applyf);
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root == NULL) return;
    bstree_apply_postfix(root->left, applyf);
    bstree_apply_postfix(root->right, applyf);
    applyf(root->item);
}



























