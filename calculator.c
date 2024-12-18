#include <stdio.h>
int is_digit(char c) {
    return c >= '0' && c <= '9';
}
int is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}
int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
int perform_operation(int a, int b, char op, int *error) {
    if (op == '/' && b == 0) {
        *error = 1; 
        return 0;
    }
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}
int process_operator(int *values, int *top, char *operators, int *opTop, int *error) {
    int b = values[(*top)--];
    int a = values[(*top)--];
    char op = operators[(*opTop)--];
    values[++(*top)] = perform_operation(a, b, op, error);
    return *error == 0;
}


int evaluate_expression(const char *exp, int *result) {
    int values[100], top = -1, error = 0;
    char operators[100], opTop = -1;

    for (int i = 0; exp[i]; i++) {
        if (is_space(exp[i])) continue;

       
        if (is_digit(exp[i])) {
            int num = 0;
            while (is_digit(exp[i])) {
                num = num * 10 + (exp[i++] - '0');
            }
            values[++top] = num;
            i--; 
        } 
       
        else if (is_operator(exp[i])) {
            while (opTop >= 0 && precedence(exp[i]) <= precedence(operators[opTop])) {
                if (!process_operator(values, &top, operators, &opTop, &error)) {
                    return 0;
                }
            }
            operators[++opTop] = exp[i];
        } else {
            
            return 0;
        }
    }

   
    while (opTop >= 0) {
        if (!process_operator(values, &top, operators, &opTop, &error)) {
            return 0;
        }
    }

    *result = values[top];
    return 1;
}

int main() {
    char input[100];
    int result;

    printf("Enter an expression: ");
    scanf("%99[^\n]", input); 

    if (evaluate_expression(input, &result)) {
        printf("Result: %d\n", result);
    } else {
        printf("Error: Invalid expression or division by zero.\n");
    }

    return 0;
}
