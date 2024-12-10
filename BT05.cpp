#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 100
#define SIZE 100
typedef struct Stack{
    char array[MAX];
    int top;
} Stack;

void createInitStack(Stack* stack){
    stack->top = -1;
}

int isEmpty(Stack* stack){
    if(stack->top == -1){
        return 1;
    }
    return 0;
}

int isFull(Stack* stack){
    if(stack->top >= MAX - 1){
        return 1;
    }
    return 0;    
}
void pushElement(Stack* stack, int newData){
    if(isFull(stack)){
        printf("Sorry, the stack is full\n");
        return;
    }
    stack->array[++(stack->top)] = newData;
}
void printArray(Stack* stack){
	for (int i = 0; i < stack->top / 2; i++) {
        char temp = stack->array[i];
        stack->array[i] = stack->array[stack->top - i];
        stack->array[stack->top - i] = temp;
    }
    for(int i = 0; i <= stack->top; i++){
        printf(" %c ", stack->array[i]);
    }
    printf("\n");
}
void peekElement(Stack* stack){
	if(isEmpty(stack)){
		printf("Sorry,the stack is empty\n");
		return;
	}
	printf("Phan tu tren cung la: %d",stack->array[stack->top]);
}
int main(){
	Stack stack;
	createInitStack(&stack);
	char text[SIZE];
	printf("Nhap chuoi ki tu: ");
	fgets(text, SIZE, stdin);
	text[strcspn(text, "\n")] = '\0';
    printf("In tung ky tu cua chuoi:\n");
    for (int i = 0; text[i] != '\0'; i++) {
        pushElement(&stack,text[i]);
    }
    printArray(&stack);

}

