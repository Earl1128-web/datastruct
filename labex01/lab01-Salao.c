#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>
#include <stdlib.h>

/* B1 */
void valueChange(int *ptr);

/*
B2:
The array's element count must be passed separately because an array
parameter behaves like a pointer inside a function. sizeof(a) reports
the size of the pointer, not the size of the original array.
*/
void printArray(const int a[], int n);

/* B3 */
void fillArray(int *numbers, int count);
void displayValues(int *numbers, int count);

/*
B4:
The caller is responsible for freeing the memory returned by this function.
*/
int *createArray(int count);


int main() {

    /* =========================
       B1 - A pointer is an address
       ========================= */

    int num = 5;
    int *ptr = &num;

    printf("===== B1: POINTER =====\n");

    printf("Original value: %d\n", num);
    printf("Address of num: %p\n", (void *)&num);
    printf("Value through pointer: %d\n", *ptr);

    valueChange(ptr);

    printf("Value after function call: %d\n", num);


    /* =========================
       B2 - An array decays
       ========================= */

    printf("\n===== B2: ARRAY DECAY =====\n");

    int sixNums[] = {5, 10, 15, 20, 25, 30};

    int theSize = sizeof(sixNums) / sizeof(*sixNums);

    printf("Size obtained in main: %d elements\n", theSize);

    printArray(sixNums, theSize);


    /* =========================
       B3 - The heap
       ========================= */

    printf("\n===== B3: THE HEAP =====\n");

    int count;

    printf("Enter count: ");

    if (scanf("%d", &count) != 1 || count <= 0) {
        printf("Invalid count.\n");
        return 1;
    }

    int *numbers = malloc(count * sizeof(int));

    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    fillArray(numbers, count);

    printf("Computed values: ");
    displayValues(numbers, count);

    free(numbers);
    numbers = NULL;

    printf("Memory released successfully.\n");


    /* =========================
       B4 - Ownership
       ========================= */

    printf("\n===== B4: OWNERSHIP =====\n");

    int *ownedNumbers = createArray(count);

    if (ownedNumbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Values created by the function: ");
    displayValues(ownedNumbers, count);

    /*
    main() owns the returned memory,
    so main() is responsible for freeing it.
    */
    free(ownedNumbers);
    ownedNumbers = NULL;

    printf("Memory released by main.\n");


    return 0;
}


/* =========================
   B1 - Pointer function
   ========================= */

void valueChange(int *ptr) {

    *ptr = 0;

    printf("Value inside function: %d\n", *ptr);
}


/* =========================
   B2 - Array decay function
   ========================= */

void printArray(const int a[], int n) {

    printf("Size obtained inside function: %zu bytes\n", sizeof(a));

    printf("Array values: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }

    printf("\n");

    /* One element accessed in two ways */

    printf("With brackets: %d\n", a[0]);

    printf("Without brackets: %d\n", *(a + 0));
}


/* =========================
   B3 - Fill heap array
   ========================= */

void fillArray(int *numbers, int count) {

    for (int i = 0; i < count; i++) {

        /* Values are computed, not manually entered */
        numbers[i] = (i + 1) * 10;
    }
}


/* =========================
   Display values
   ========================= */

void displayValues(int *numbers, int count) {

    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");
}


/* =========================
   B4 - Ownership
   ========================= */

/*
The caller is responsible for freeing the memory returned by this function.
*/

int *createArray(int count) {

    int *numbers = malloc(count * sizeof(int));

    if (numbers == NULL) {
        return NULL;
    }

    for (int i = 0; i < count; i++) {

        /* Compute the values */
        numbers[i] = (i + 1) * 10;
    }

    return numbers;
}