#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void output_tree(t_btree *root);

int main() {
    t_btree *root = bstree_create_node(4);
    t_btree *node1 = bstree_create_node(3);
    t_btree *node2 = bstree_create_node(5);

    root->right = node2;
    root->left = node1;

    printf("INPUT: 3 5\n");
    printf("OUTPUT:\n");
    output_tree(root);
    if ((root->left->item == 3) && (root->right->item == 5)) {
        printf("RESULT: SUCCESS");
    } else {
        printf("RESULT: FAIL");
    }
    free(root);
    free(node1);
    free(node2);
    return 0;
}

void output_tree(t_btree *root) {
    printf("  %d\n", root->item);
    printf(" / \\\n");
    printf("%d   %d\n", root->left->item, root->right->item);
}
