#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "door_struct.h"

struct node *init(struct door *door) {
    struct node *new_door = (struct node*)malloc(sizeof(struct node));
    new_door->door = door;
    new_door->next = NULL;
    return new_door;
}

struct node *add_door(struct node* elem, struct door *door) {
    struct node *new_door = (struct node*)malloc(sizeof(struct node));
    new_door->door = door;
    struct node *temp = elem->next;
    elem->next = new_door;
    new_door->next = temp;
    return new_door;
}

struct node *find_door(int door_id, struct node *root) {
    while (root) {
        if (root->door->id == door_id) {
            return root;
        }
        if (root->next == NULL) {
            break;
        }
        root = root->next;
    }
    return NULL;
}

struct node *remove_door(struct node *elem, struct node *root) {
    struct node *prenode = NULL;
    while (root) {
        if (root->next == elem) {
            prenode = root;
            break;
        }
        root = root->next;
    }
    if (prenode == NULL) {
        printf("ERROR! Door for removal was not found");
        return NULL;
    }
    prenode->next = elem->next;
    free(elem->door);
    free(elem);
    return prenode;
}

void destroy(struct node* root) {
    struct node *temp;
    while (root != NULL) {
        temp = root;
        root = root->next;
    //    free(temp->door);
        free(temp);
    }
}
