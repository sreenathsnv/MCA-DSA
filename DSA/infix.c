#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to stack
void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack
char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

// Function to get the top item from stack
char peek(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}

// Function to check if the given character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to return the precedence of operators
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    return -1;
}

// Function to convert infix expression to postfix
void infixToPostfix(char* expression) {
    struct Stack* stack = createStack(strlen(expression));
    int i, k;
    
    for (i = 0, k = -1; expression[i]; ++i) {
        if (isalnum(expression[i])) {
            expression[++k] = expression[i];
        } else if (expression[i] == '(') {
            push(stack, expression[i]);
        } else if (expression[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                expression[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return; // Invalid expression
            else
                pop(stack);
        } else {
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack)))
                expression[++k] = pop(stack);
            push(stack, expression[i]);
        }
    }
    
    while (!isEmpty(stack))
        expression[++k] = pop(stack);
    
    expression[++k] = '\0';
}

// Function to evaluate postfix expression
int evaluatePostfix(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    int i;
    
    for (i = 0; postfix[i]; ++i) {
        if (isdigit(postfix[i])) {
            push(stack, postfix[i] - '0');
        } else {
            int val1 = pop(stack);
            int val2 = pop(stack);
            
            switch (postfix[i]) {
                case '+': push(stack, val2 + val1); break;
                case '-': push(stack, val2 - val1); break;
                case '*': push(stack, val2 * val1); break;
                case '/': push(stack, val2 / val1); break;
            }
        }
    }
    
    return pop(stack);
}

int main() {
    char expression[100];
    printf("Enter an infix expression: ");
    scanf("%s", expression);

    infixToPostfix(expression);
    printf("Postfix expression: %s\n", expression);

    int result = evaluatePostfix(expression);
    printf("Result after evaluation: %d\n", result);

    return 0;
}

