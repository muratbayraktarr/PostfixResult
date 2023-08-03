#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Push an element onto the stack
void push(Stack *stack, int item) {
    stack->items[++stack->top] = item;
}

// Pop and return the top element from the stack
int pop(Stack *stack) {
    return stack->items[stack->top--];
}
// Evaluate the postfix expression and return the result
int evaluatePostfixExpression(char *expression) {
    Stack stack;
    stack.top = -1; // Initialize stack's top to -1, indicating it's empty
    int i, operand1, operand2, result;

    for (i = 0; expression[i] != '\0'; i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            // If the character is an operand, push it to the stack
            push(&stack, expression[i] - '0');
        } else {
            // If the character is an operator, pop two operands from the stack
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            // Perform the operation based on the operator
            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid expression!\n");
                    return -1;
            }

            // Push the result back to the stack
            push(&stack, result);
        }
    }

    // The final result will be at the top of the stack
    return pop(&stack);
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter myMath statement: ");
    scanf("%s", expression);

    int result = evaluatePostfixExpression(expression);
    printf("Result of myMath statement: %d\n", result);

    return 0;
}

