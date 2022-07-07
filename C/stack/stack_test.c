#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// TEST DATA

void display_stack(struct stack *stack);
void test_push(struct stack *stack, int item);
void test_pop(struct stack *stack);

int main() {
    struct stack *cur_stack = init(1);
    cur_stack = push(cur_stack, 2);
    test_push(cur_stack, 3);
    test_pop(cur_stack);
    destroy(cur_stack);
    return 0;
}

void test_push(struct stack *stack, int item) {
    printf("------PUSH_TEST\n");
    printf("INPUT: %d\n", item);
    stack = push(stack, item);
    printf("OUTPUT:\n");
    display_stack(stack);
    if (stack->item == item) {
        printf("\nRESULT: SUCCESS");
    } else {
        printf("\nRESULT: FAIL");
    }
    free(stack);
}

void test_pop(struct stack *stack) {
    printf("\n------POP_TEST\n");
    printf("INPUT:\n");
    display_stack(stack);
    stack = pop(stack);
    printf("\nOUTPUT:\n");
    display_stack(stack);
    if (stack->item == 1) {
        printf("\nRESULT: SUCCESS");
    } else {
        printf("\nRESULT: FAIL");
    }
}

void display_stack(struct stack *stack) {
    struct stack *temp;
    temp = stack;
    while (temp->prev != NULL) {
        printf("%d\n", temp->item);
        temp = temp->prev;
    }
    printf("%d", temp->item);
}
