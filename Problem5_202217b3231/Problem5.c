#include <stdio.h>

#define n 5

int main() {
    int queue[n], ch, front = 0, rear = 0, j = 1, x = n;
    printf("\nQueue using Array!");
    printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Exit");
    while (1) {
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                if (rear == x)
                    printf("\nQueue is FULL!");
                else {
                    printf("\nEnter no. %d: ", j++);
                    scanf("%d", &queue[rear++]);
                }
                break;
            case 2:
                if (front == rear)
                    printf("\nQueue is EMPTY!");
                else {
                    printf("\nDeleted element is %d!", queue[front++]);
                    x--;
                }
                break;
            case 3:
                printf("\nQueue elements are:");
                if (front == rear)
                    printf("\nQueue is EMPTY!");
                else {
                    for (int i = front; i < rear; i++) {
                        printf("\n%d", queue[i]);
                    }
                }
                break;
            case 4:
                return 0;
            default:
                printf("\nEnter valid choice!");
        }
    }
}
