#include <stdio.h>

int stack[100];
int top = -1;
int n, x, choice;

void pop();
void push();
void display();

int main() {
    printf("\nEnter the size of stack (MAX 100): ");
    scanf("%d", &n);

    printf("\n\tStack Operations using ARRAY");
    printf("\n\t----------------------------");
    printf("\n\t1. Push\n\t2. Pop\n\t3. Display\n\t4. EXIT");

    do {
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nEnter a valid choice (1/2/3/4)\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void push() {
    if (top >= n - 1) {
        printf("\nSTACK is FULL! Cannot push more elements.\n");
    } else {
        printf("\nEnter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("Element %d pushed successfully.\n", x);
    }
}

void pop() {
    if (top <= -1) {
        printf("\nSTACK is EMPTY! Cannot pop from empty stack.\n");
    } else {
        printf("\nThe popped element is %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top >= 0) {
        printf("\nThe elements in the stack are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    } else {
        printf("\nThe stack is empty.\n");
    }
}
