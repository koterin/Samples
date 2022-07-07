#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void output_tree1(t_btree *root);
void output_tree2(t_btree *root);

int main() {
    t_btree *root = bstree_create_node(4);
    t_btree *node1 = bstree_create_node(3);

    root->left = node1;

    printf("INPUT: 5\n");
    printf("OUTPUT:\n");
    bstree_insert(root, 5, comparator);
    output_tree1(root);
    if ((root->left->item == 3) && (root->right->item == 5)) {
        printf("RESULT: SUCCESS");
    } else {
        printf("RESULT: FAIL");
    }

    printf("\nINPUT: 2\n");
    printf("OUTPUT:\n");
    bstree_insert(root, 2, comparator);
    output_tree2(root);
    if (root->left->left->item == 2) {
        printf("RESULT: SUCCESS");
    } else {
        printf("RESULT: FAIL");
    }

    free(root->right);
    free(root->left->left);
    free(root);
    free(node1);
    return 0;
}

void output_tree1(t_btree *root) {
    printf("     %d\n", root->item);
    printf("    / \\\n");
    printf("   %d   %d\n", root->left->item, root->right->item);
}

void output_tree2(t_btree *root) {
    printf("     %d\n", root->item);
    printf("    / \\\n");
    printf("   %d   %d\n", root->left->item, root->right->item);
    printf("  /\n");
    printf(" %d\n", root->left->left->item);
}

