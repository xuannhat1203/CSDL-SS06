#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Stack {
    char array[MAX];
    int top;
} Stack;

void createInitStack(Stack* stack) {
    stack->top = -1;
}

int isFull(Stack* stack) {
    return stack->top >= MAX - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void pushElement(Stack* stack, char newData) {
    if (isFull(stack)) {
        printf("Sorry, the stack is full\n");
        return;
    }
    stack->array[++(stack->top)] = newData;
}

char popElement(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, cannot pop\n");
        return '\0';
    }
    return stack->array[(stack->top)--];
}

int kiemTraHopLe(const char* expression) {
    Stack stack;
    createInitStack(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            pushElement(&stack, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&stack)) {
                return 0;  
            }
            char open = popElement(&stack);
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                return 0;  
            }
        }
    }
    return isEmpty(&stack);  
}

int main() {
    char text[MAX];
    printf("Nh?p bi?u th?c c?n ki?m tra: ");
    fgets(text, MAX, stdin);
    text[strcspn(text, "\n")] = '\0';  

    if (kiemTraHopLe(text)) {
        printf("Bi?u th?c h?p l?\n");
    } else {
        printf("Bi?u th?c không h?p l?\n");
    }
    return 0;
}

