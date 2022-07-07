#ifndef SRC_STACK_H_
#define SRC_STACK_H_

struct stack {
    int item;
    struct stack *prev;
};

struct stack *init(int item);
struct stack *push(struct stack *stack, int item);
struct stack *pop(struct stack *stack);
void destroy(struct stack* stack);

#endif  // SRC_STACK_H_
