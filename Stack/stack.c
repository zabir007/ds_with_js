#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Stack {
    int top;
    unsigned cap;
    int* arr;
};
typedef struct Stack st;

st* create_stack(unsigned cap)
{
    st* stack = malloc(sizeof(st));
    stack->cap = cap;
    stack->top = -1;
    stack->arr = malloc(sizeof(st));
    return stack;
}

int isFull(st* stack)
{
    return stack->top == stack->cap - 1;
}

int isEmpty(st* stack)
{
    return stack->top == -1;
}

void push(st* stack, int data)
{
    if(isFull(stack))
        return;
    stack->arr[++stack->top] == data;
    printf("%d pushed to stack\n", data);
}

int pop(st* stack)
{
    if(isEmpty(stack))
        return INT_MIN;
    return stack->arr[stack->top--];
}


int main(int argc, char const *argv[])
{
    st* stack = create_stack(3);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 30);

    printf("%d ",pop(stack));
    push(stack, 30);

    
 

    

    return 0;
}
