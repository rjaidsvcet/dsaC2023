#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
    int* array;
    int top;
    unsigned capacity;
};

struct Stack* createStack (unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc (sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = (int*) malloc (stack -> capacity * sizeof(int));
    return stack;
}

int isFull (struct Stack* stack) {
    return stack -> top == stack -> capacity - 1;
}

int isEmpty (struct Stack* stack) {
    return stack -> top == -1;
}

void push (struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack -> array[++ stack -> top] = item;
    printf ("%d element is pushed to stack \n", item);
}

int pop (struct Stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;
    return stack -> array[stack -> top--];
}

int peek (struct Stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;
    return stack -> array[stack -> top];
}

int main () {
    struct Stack* stack = createStack(100);
  
    push (stack, 10);
    push (stack, 20);
    push (stack, 30);
    
    printf ("%d is the top element \n", peek (stack));
    
    pop (stack);

    printf ("%d is the top element \n", peek (stack));
    
    return 0;
}