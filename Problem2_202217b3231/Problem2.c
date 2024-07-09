// Preamble
// The list data structures are widely used in:
// Sorting Algorithms: Lists are essential to constructing efficient sorting algorithms such as quick
// sort and merge sort.
// Data Analytics: Lists are often used to represent datasets in data analytics and machine learning.
// Database Management Systems

// Steps
// Step 1: Define structure variables and functions.
// Step 2: Get the values for two polynomial expression with co efficient and term.
// Step 3: Add two terms when the co efficient are same. If not store the higher order in the
// resultant polynomial.
// Step 4: Display the result of addition
#include <stdio.h>
#include <stdlib.h>

struct poly {
    int coeff;
    int expo;
};

// Function prototypes
int readPoly(struct poly []);
int addPoly(struct poly [], struct poly [], int, int, struct poly []);
void displayPoly(struct poly [], int);

int main() {
    struct poly p1[10], p2[10], p3[10];
    int t1, t2, t3;

    t1 = readPoly(p1);
    printf("\nFirst Polynomial: ");
    displayPoly(p1, t1);

    t2 = readPoly(p2);
    printf("\nSecond Polynomial: ");
    displayPoly(p2, t2);

    t3 = addPoly(p1, p2, t1, t2, p3);
    printf("\nResultant polynomial after addition: ");
    displayPoly(p3, t3);

    return 0;
}

int readPoly(struct poly p[10]) {
    int t;

    printf("\nEnter the total number of terms in polynomial: ");
    scanf("%d", &t);

    printf("\nEnter the Coefficient and Exponent in Descending order:\n");

    for (int i = 0; i < t; i++) {
        printf("Enter the COEFFICIENT(%d): ", i + 1);
        scanf("%d", &p[i].coeff);
        printf("Enter the EXPONENT(%d): ", i + 1);
        scanf("%d", &p[i].expo);
    }
    return t;
}

int addPoly(struct poly p1[10], struct poly p2[10], int t1, int t2, struct poly p3[10]) {
    int i = 0, j = 0, k = 0;

    while (i < t1 && j < t2) {
        if (p1[i].expo == p2[j].expo) {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            j++;
            k++;
        } else if (p1[i].expo > p2[j].expo) {
            p3[k].coeff = p1[i].coeff;
            p3[k].expo = p1[i].expo;
            i++;
            k++;
        } else {
            p3[k].coeff = p2[j].coeff;
            p3[k].expo = p2[j].expo;
            j++;
            k++;
        }
    }
    while (i < t1) {
        p3[k].coeff = p1[i].coeff;
        p3[k].expo = p1[i].expo;
        i++;
        k++;
    }
    while (j < t2) {
        p3[k].coeff = p2[j].coeff;
        p3[k].expo = p2[j].expo;
        j++;
        k++;
    }
    return k;
}

void displayPoly(struct poly p[10], int term) {
    for (int i = 0; i < term - 1; i++) {
        printf("%dx^%d + ", p[i].coeff, p[i].expo);
    }
    printf("%dx^%d\n", p[term - 1].coeff, p[term - 1].expo);
}
