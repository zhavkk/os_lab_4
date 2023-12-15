#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

int main() {
    printf("1 arg1 arg2 - PrimeCount function\n2 - Sort function\n3 exit\n");
    int com;
    int a, b;
    int size;
    int *array = NULL;

    printf("Input the command: ");
    scanf("%d", &com);

    while (com != 3) {
        switch (com) {
            case 1:
                printf("Input a and b: ");
                scanf("%d %d", &a, &b);
                printf("PrimeCount(%d, %d) = %d\n", a, b, PrimeCount(a, b));

                printf("Input the command: ");
                scanf("%d", &com);
                break;
            case 2:
                printf("Input the size of your array: ");
                scanf("%d", &size);
                array = (int *)malloc(size * sizeof(int));

                printf("Input your array: ");
                for (int i = 0; i < size; ++i) {
                    scanf("%d", &array[i]);
                }

                int *sortedArray = sort(array, size);

                printf("Sorted array: ");
                for (int i = 0; i < size; ++i) {
                    printf("%d ", sortedArray[i]);
                }
                printf("\n");

                free(sortedArray);

                printf("Input the command: ");
                scanf("%d", &com);
                break;
            case 3:
                break;
            default:
                printf("Incorrect input\n");
                exit(1);
                break;
        }
    }

    return 0;
}
