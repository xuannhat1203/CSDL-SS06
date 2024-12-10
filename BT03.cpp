#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct Stack{
    int array[MAX];
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
    for(int i = 0; i <= stack->top; i++){
        printf(" %d ", stack->array[i]);
    }
    printf("\n");
}
int main(){
	Stack stack;
	createInitStack(&stack);
	int n;
	printf("Nhap so luong phan tu: ");
	scanf("%d",&n);
	int newData;
	if(n<=0){
		printf("danh sach khong rong");
		return 0;
	}
	for(int i=0;i<n;i++){
		printf("Nhap phan tu thu %d: ",i+1);
		scanf("%d",&newData);
		pushElement(&stack,newData);
	}
	printArray(&stack);
	if(isEmpty(&stack) == -1){
		printf("danh sach rong");
		return 0;
	}else{
		printf("danh sach khong rong");
	}
}

