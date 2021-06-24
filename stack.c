#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//template for a node in the stack
struct Stack {
    int data;
    int index;
    unsigned int capacity;
    struct Stack* next;
};

//creates an empty stack by creating its root
//stack elements follow the root
struct Stack* createEmptyStack(unsigned int capacity){
    struct Stack* root = (struct Stack*)malloc(sizeof(struct Stack));
    root->capacity = capacity;
    root->index = -1;
    root->next = NULL;
    return root;
}

//checks whether the stack is empty
int isEmpty(struct Stack* stack){
    if (stack){ //checks if the stack exists
        return stack->index == -1;
    }
    return 0;
}

//checks whether the stack is full
int isFull(struct Stack* stack){
    if (stack){
        return stack->index == stack->capacity - 1;
    }
    return 0;
}

//puts a number into the stack
void push(struct Stack** stack, int data){
    if (*stack){
        //checks if the stack is not full
        if (!(isFull(*stack))){
            //a new stack element is created
            struct Stack* newNode = (struct Stack*)malloc(sizeof(struct Stack));
            newNode->data = data;
            newNode->index = ((*stack)->index) + 1;
            newNode->capacity = (*stack)->capacity;
            //connects the elements
            newNode->next = (*stack);
            //"stack" now points to top element of the stack
            *stack = newNode;
        }
        else{
            printf("The stack is full! No new elements could be added.\n");
        }
    }
    else {
        printf("The stack does not exist! You must create it first.\n");
    }
};

//retrieves a number out of the stack
int pop(struct Stack** stack){
    if (*stack){
        if (!(isEmpty(*stack))){
            struct Stack* oldNode = (*stack);
            int data = (*stack)->data;
            (*stack) = (*stack)->next;
            free(oldNode);
            return data;
        }
        else {
            printf("The stack is empty! No elements could be retrieved.\n");
            return INT_MIN;
        }
    }
    else {
        printf("The stack does not exist! You must create it first.\n");
        return INT_MIN;
    }
}

//destroys the stack
void destroyStack(struct Stack** stack){
    if (*stack){
        while (!(isEmpty(*stack))){
            struct Stack* data = (*stack);
            *stack = (*stack)->next;
            free(data);
        }
        free(*stack);
        *stack = NULL;
    }
    else{
        printf("Could not destroy the stack, it does not exist!");
    }
}
