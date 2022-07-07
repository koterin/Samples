#include "list.h"
#include "door_struct.h"
#include <stdio.h>
#include <stdlib.h>

// TEST DATA

void display_doors(struct node *elem);
void test_add_door(struct node *test, struct door *test_door);
void test_remove_door(struct node *test, struct node *root);

int main() {
    struct door *test_door1 = (struct door *)malloc(sizeof(struct door));
    test_door1->id = 2;
    test_door1->status = 0;

    struct door *test_door2 = (struct door *)malloc(sizeof(struct door));
    test_door2->id = 36;
    test_door2->status = 1;

    struct node *root = init(test_door1);
    struct node *test_node1 = add_door(root, test_door2);

    test_add_door(test_node1, test_door1);
    printf("\n");
    test_remove_door(test_node1, root);
    destroy(root);
    free(test_door1);
    return 0;
}

void display_doors(struct node *elem) {
    while (elem->next != NULL) {
        printf("%d, %d\n", elem->door->id, elem->door->status);
        elem = elem->next;
    }
    printf("%d, %d", elem->door->id, elem->door->status);
}

void test_add_door(struct node *test, struct door *test_door) {
    printf("------ADD_DOOR_TEST\n");
    printf("INPUT: %d, %d\n", test_door->id, test_door->status);
    struct node *test_node2 = add_door(test, test_door);
    printf("OUTPUT: %d, %d\n", test_node2->door->id, test_node2->door->status);
    if ((test_node2->door->id == test_door->id) && (test_node2->door->status == test_door->status)) {
        printf("RESULT: SUCCESS");
    } else {
        printf("RESULT: FAIL");
    }
}

void test_remove_door(struct node *test, struct node *root) {
    struct door *temp = test->door;
    printf("------REMOVE_DOOR_TEST\n");
    printf("INPUT:\n");
    display_doors(root);

    remove_door(test, root);
    printf("\nOUTPUT:\n");
    display_doors(root);
    if (find_door(temp->id, root) == NULL) {
        printf("\nRESULT: SUCCESS");
    } else {
        printf("\nRESULT: FAIL");
    }
}

