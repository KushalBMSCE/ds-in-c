#include <stdio.h>
#include <stdlib.h>

void push(int *stack, int *top, int *max)
{
    int value;
    if(*top == *max-1){
        printf("Stack Overflow \n");
    }
    else{
        for (int i=0;i<*max;i++){
            printf("Enter value %d :\n",(i+1));
            scanf("%d",&value);
            stack[++(*top)]=value;
        }
    }
}
int pop(int *stack, int *top, int *max)
{
    if(*top== -1){
        printf("Stack Underflow \n");
        return -1;
    }
    else {
        return stack[(*top)--];
    }
}
void display(int *stack, int *top, int *max)
{
     if(*top== -1){
        printf("Stack Underflow \n");
        return -1;
    }
    else{
        for (int i=*top;i>=0;i--){
            printf("Value %d : %d \n",i+1,stack[i]);
        }
    }
}

void main()
{
    int max = 5;
    int stack[max];
    int top = -1;
    int choice;
    while(1){
        printf("Select among stack operations below \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push(stack,&top,&max);
            break;
        case 2:
            printf("Successfully popped %d \n",pop(stack,&top,&max));
            break;
        case 3:
            display(stack,&top,&max);
            break;
        default:
            printf("invalid input ! \n");
            break;

        }
    }
}
