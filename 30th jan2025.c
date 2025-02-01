// Q: Decode a String Encoded with Run-Length Encoding
// Given a compressed string like "3[a]2[bc]", expand it to "aaabcbc".
// Example: 
// Input: "3[a2[c]]"
// Output: "accaccacc"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    char **data;
    int top;
    int capacity;

}Stack;
Stack* createStack(int capacity){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (char**)malloc(sizeof(char*) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
    }
    Stack* push(Stack* stack, char* data){
        if(stack->top == stack->capacity - 1){
            stack->capacity *= 2;
            stack->data = (char**)realloc(stack->data, sizeof(char*) * stack->capacity
            );
            }
            stack->data[++stack->top] = data;
            return stack;
            }











