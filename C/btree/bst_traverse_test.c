#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void output_tree(t_btree *root);

int main() {
    t_btree *root = bstree_create_node(4);
    t_btree *node1 = bstree_create_node(3);

    root->left = node1;
    bstree_insert(root, 5, comparator);

    printf("-----INFIX\n");
    printf("INPUT:\n");
    output_tree(root);
    printf("OUTPUT:\n");

    bstree_apply_infix(root, leaf_print);

    if ((root->left->item == 3) && (root->right->item == 5)) {
        printf("\nRESULT: SUCCESS");
    } else {
        printf("\nRESULT: FAIL");
    }

    printf("\n-----PREFIX\n");
    printf("INPUT:\n");
    output_tree(root);
    printf("OUTPUT:\n");

    bstree_apply_prefix(root, leaf_print);

    if ((root->left->item == 3) && (root->right->item == 5)) {
        printf("\nRESULT: SUCCESS");
    } else {
        printf("\nRESULT: FAIL");
    }

    printf("\n-----POSTFIX\n");
    printf("INPUT:\n");
    output_tree(root);
    printf("OUTPUT:\n");

    bstree_apply_postfix(root, leaf_print);

    if ((root->left->item == 3) && (root->right->item == 5)) {
        printf("\nRESULT: SUCCESS");
    } else {
        printf("\nRESULT: FAIL");
    }

    free(root->right);
    free(root);
    free(node1);

    return 0;
}

void output_tree(t_btree *root) {
    printf("     %d\n", root->item);
    printf("    / \\\n");
    printf("   %d   %d\n", root->left->item, root->right->item);
}
