
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Stack structure for storing strings
typedef struct {
   char* data[100];
   int top;
} Stack;
// Initialize stack
void initStack(Stack* stack) {
   stack->top = -1;
}
// Push string onto stack
void push(Stack* stack, char* str) {
   stack->data[++stack->top] = strdup(str);
}
// Pop string from stack
char* pop(Stack* stack) {
   if (stack->top == -1) return "";
   return stack->data[stack->top--];
}
// Check if the character is an operator
int isOperator(char ch) {
   return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char* prefixToPostfix(char* prefix) {
   Stack stack;
   initStack(&stack);
   int len = strlen(prefix);
   for (int i = len - 1; i >= 0; i--) {
       if (isalnum(prefix[i])) {  // Operand
           char operand[2] = {prefix[i], '\0'};
           push(&stack, operand);
       }
       else if (isOperator(prefix[i])) {  // Operator
           char* op1 = pop(&stack);
           char* op2 = pop(&stack);
           char newExpr[100] = "";
           strcat(newExpr, op1);
           strcat(newExpr, op2);
           strncat(newExpr, &prefix[i], 1); // Append operator
           push(&stack, newExpr);
       }
   }
   return stack.data[stack.top];
}
// 2. Prefix to Infix
char* prefixToInfix(char* prefix) {
   Stack stack;
   initStack(&stack);
   int len = strlen(prefix);
   for (int i = len - 1; i >= 0; i--) {
       if (isalnum(prefix[i])) {
           char operand[2] = {prefix[i], '\0'};
           push(&stack, operand);
       }
       else if (isOperator(prefix[i])) {
           char* op1 = pop(&stack);
           char* op2 = pop(&stack);
           char newExpr[100] = "(";
           strcat(newExpr, op1);
           strncat(newExpr, &prefix[i], 1);
           strcat(newExpr, op2);
           strcat(newExpr, ")");
           push(&stack, newExpr);
       }
   }
   return stack.data[stack.top];
}
// 3. Postfix to Prefix
char* postfixToPrefix(char* postfix) {
   Stack stack;
   initStack(&stack);
   int len = strlen(postfix);
   for (int i = 0; i < len; i++) {
       if (isalnum(postfix[i])) {
           char operand[2] = {postfix[i], '\0'};
           push(&stack, operand);
       }
       else if (isOperator(postfix[i])) {
           char* op2 = pop(&stack);
           char* op1 = pop(&stack);
           char newExpr[100] = "";
           strncat(newExpr, &postfix[i], 1);
           strcat(newExpr, op1);
           strcat(newExpr, op2);
           push(&stack, newExpr);
       }
   }
   return stack.data[stack.top];
}
// 4. Postfix to Infix
char* postfixToInfix(char* postfix) {
   Stack stack;
   initStack(&stack);
   int len = strlen(postfix);
   for (int i = 0; i < len; i++) {
       if (isalnum(postfix[i])) {
           char operand[2] = {postfix[i], '\0'};
           push(&stack, operand);
       }
       else if (isOperator(postfix[i])) {
           char* op2 = pop(&stack);
           char* op1 = pop(&stack);
           char newExpr[100] = "(";
           strcat(newExpr, op1);
           strncat(newExpr, &postfix[i], 1);
           strcat(newExpr, op2);
           strcat(newExpr, ")");
           push(&stack, newExpr);
       }
   }
   return stack.data[stack.top];
}
// 5. Infix to Postfix
int precedence(char op) {
   if (op == '+' || op == '-') return 1;
   if (op == '*' || op == '/') return 2;
   if (op == '^') return 3;
   return 0;
}
char* infixToPostfix(char* infix) {
   Stack stack;
   initStack(&stack);
   static char output[100] = "";
   int len = strlen(infix);
   for (int i = 0; i < len; i++) {
       if (isalnum(infix[i])) {
           strncat(output, &infix[i], 1);
       }
       else if (infix[i] == '(') {
           char temp[2] = {infix[i], '\0'};
           push(&stack, temp);
       }
       else if (infix[i] == ')') {
           while (stack.top != -1 && stack.data[stack.top][0] != '(') {
               strcat(output, pop(&stack));
           }
           pop(&stack);
       }
       else {
           while (stack.top != -1 && precedence(stack.data[stack.top][0]) >= precedence(infix[i])) {
               strcat(output, pop(&stack));
           }
           char temp[2] = {infix[i], '\0'};
           push(&stack, temp);
       }
   }
   while (stack.top != -1) {
       strcat(output, pop(&stack));
   }
   return output;
}
// 6. Infix to Prefix
char* infixToPrefix(char* infix) {
   static char reversed[100], prefix[100] = "";
   int len = strlen(infix);
   // Reverse infix
   for (int i = 0; i < len; i++) {
       reversed[i] = (infix[len - i - 1] == '(') ? ')' :
                     (infix[len - i - 1] == ')') ? '(' : infix[len - i - 1];
   }
   reversed[len] = '\0';
   // Convert to postfix
   char* postfix = infixToPostfix(reversed);
   // Reverse postfix to get prefix
   len = strlen(postfix);
   for (int i = 0; i < len; i++) {
       prefix[i] = postfix[len - i - 1];
   }
   prefix[len] = '\0';
   return prefix;
}
// Main function
int main() {
   char expr[100];
   int choice;
   printf("Enter expression: ");
   scanf("%s", expr);
   printf("\nChoose conversion:\n");
   printf("1. Prefix to Postfix\n2. Prefix to Infix\n");
   printf("3. Postfix to Prefix\n4. Postfix to Infix\n");
   printf("5. Infix to Postfix\n6. Infix to Prefix\n");
   scanf("%d", &choice);
   switch (choice) {
       case 1: printf("Postfix: %s\n", prefixToPostfix(expr)); break;
       case 2: printf("Infix: %s\n", prefixToInfix(expr)); break;
       case 3: printf("Prefix: %s\n", postfixToPrefix(expr)); break;
       case 4: printf("Infix: %s\n", postfixToInfix(expr)); break;
       case 5: printf("Postfix: %s\n", infixToPostfix(expr)); break;
       case 6: printf("Prefix: %s\n", infixToPrefix(expr)); break;
       default: printf("Invalid choice!\n");
   }
   return 0;
}