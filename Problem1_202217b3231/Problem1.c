// Preamble
// In computer science, an abstract data type (ADT) is a mathematical model for data types, defined
// by its behavior (semantics) from the point of view of a user of the data, specifically in terms of
// possible values, possible operations on data of this type, and the behavior of these operations.
// In List ADT, the data are generally stored in key sequence in a list. We can implement list using
// arrays  or  linked  lists  which  has  a  head  structure  consisting  of  count,  pointers  and  address  of
// compare function needed to compare the data in the list.

// Steps
// Step 1: Define all global variables and functions.
// Step 2: Get the option from user and execute switch statement.
// Step 3: If it is insertion get the number from user and insert into the list.
// • If the list is empty add that number as the first element.
// • If the list id full then display it is full or else insert according to the position.
// Step 4: If it is deletion, check list is empty or not. If it is empty print empty else search that
//            element and remove the number from the list else display
// Step 5: If operation is display then list the elements in the list.
// Step 6: Stop the program

#include <stdio.h>

#define MAX 20

int b[MAX],n=0,elem;

void create() {
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the elements:\t");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void display() {
    if (n == 0)
        printf("\nThe list is empty!");
    else {
        printf("\nThe elements of the List are:\n");
        for (int i = 0; i < n; i++) {
            printf("%d\n", b[i]);
        }
    }
}

void insert() {
    int pos, p;

    printf("\nEnter the position you want to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("\nInvalid position!\n");
        return;
    }

    printf("\nEnter the element to insert: ");
    scanf("%d", &p);

    for (int i = n; i > pos; i--) {
        b[i] = b[i - 1];
    }

    b[pos] = p;
    n++;

    printf("\nThe list after insertion:\n");
    display();
}

void deletion() {
    int pos;

    if (n == 0) {
        printf("\nThe list is empty! Nothing to delete.\n");
        return;
    }

    printf("\nEnter the position you want to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("\nInvalid position!\n");
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }

    n--;

    printf("\nThe list after deletion:\n");
    display();
}

void search() {
    int found = 0;

    printf("\nEnter the element to be searched: ");
    scanf("%d", &elem);

    for (int i = 0; i < n; i++) {
        if (elem == b[i]) {
            printf("\nElement %d found at position %d\n", elem, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nElement %d not found in the list!\n", elem);
    }
}

int main() {
    int ch;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Create\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                deletion();
                break;
            case 4:
                search();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("\nEnter the correct choice!\n");
        }
    }

    return 0;
}
