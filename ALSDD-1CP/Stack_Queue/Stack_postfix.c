#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int *array;
    int capacity;
    int top;
} Stack;

Stack *create_stack(int capacity) {
    if (capacity <= 0) {
        return NULL;
    }

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }

    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(sizeof(int) * capacity);

    return stack;
}

void push(Stack *stack, int val) {
    if (stack == NULL || stack->top == stack->capacity - 1) {
        printf("The stack is full.\n");
        exit(EXIT_FAILURE);
    }
    stack->array[++stack->top] = val;
}

int pop(Stack *stack) {
    if (stack == NULL || stack->top == -1) {
        printf("The stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

bool is_operand(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

float operation(float x, char c, float y) {
    switch (c) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            if (y != 0)
                return x / y;
            else {
                printf("Division by zero error.\n");
                exit(EXIT_FAILURE);
            }
        default:
            printf("Invalid operator.\n");
            exit(EXIT_FAILURE);
    }
}

int is_empty(Stack*stack){
    return (stack->top == -1);
}

int peek(Stack*stack){
    if(is_empty(stack)){
        return -1;
    }
    return stack->array[stack->top];
}


int Priority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void valeur(char *str,float *values) {
    //float values[26]; // Assuming we have 26 variables (a-z)
    printf("Enter the values of the variables:\n");
    for (int i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            char var;
            printf("%c = ", str[i]);
            scanf("%f", &values[str[i] - 'a']); // 'a' is subtracted to map 'a' to index 0, 'b' to 1, and so on.
        }
    }
}

void convert_infix_postfix(char *infix, char *postfix) {
    int l = strlen(infix);
    Stack *stack = create_stack(l);
    int i = 0;
    int j = 0;
    
    for (i = 0; i < l; i++) {
        if (infix[i] == '(') {
            push(stack, '(');
        } else if (is_operand(infix[i])) {
            while (!is_empty(stack) && Priority(peek(stack)) >= Priority(infix[i])) {
                postfix[j++] = pop(stack);
            }
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!is_empty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            if (!is_empty(stack) && peek(stack) == '(') {
                pop(stack); // Discard the '('
            }
        } else {
            postfix[j++] = infix[i];
        }
    }

    while (!is_empty(stack)) {
        postfix[j++] = pop(stack);
    }
    postfix[j] = '\0';
}

float postfix(char T[], float values[]) {
    int l = strlen(T);
    Stack *stack = create_stack(l);
    int i = 0;
    while (T[i] != '\0') {
        if (isalpha(T[i])) {
            push(stack, values[T[i] - 'a']); 
        } else if (!is_operand(T[i])) {
            push(stack, T[i] - '0'); 
        } else {
            float y = pop(stack);
            float x = pop(stack);
            push(stack, operation(x, T[i], y));
        }
        i++;
    }
    if (stack->top == -1) {
        printf("Invalid expression.\n");
        exit(EXIT_FAILURE);
    }
    return pop(stack);
}

int main() {
    char expression[50];
    char postfix_expression[50];
    float values[26]; // Assuming we have 26 variables (a-z)

    printf("\nEnter the infix expression: ");
    fgets(expression, 50, stdin);
    expression[strlen(expression) - 1] = '\0'; // Removing the newline character

    convert_infix_postfix(expression, postfix_expression);
    printf("Postfix expression: %s\n", postfix_expression);

    valeur(postfix_expression,values); // Input values for variables

    printf("Result: %f\n", postfix(postfix_expression, values));

    return 0;
}
