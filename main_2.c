#include <stdio.h>
#include <dlfcn.h>

int main() {
    int com, a, b, size;
    int *array = NULL;
    void *library;
    char name1[] = "PrimeCount";
    char name2[] = "sort";

    printf("0 - change realisation\n1 arg1 arg2 - PrimeCount function\n2 your array - Sort function\n3 exit\n");
    printf("Input your command: ");
    scanf("%d", &com);

    library = dlopen("librealization1.so", RTLD_NOW);

    if (!library) {
        fprintf(stderr, "dlopen error: %s\n", dlerror());
        return 1;
    }

    while (com != 3) {
        switch (com) {
            case 0:
                dlclose(library);
                if (library == 1) {
                    library = dlopen("librealization1.so", RTLD_NOW);
                } else {
                    library = dlopen("librealization2.so", RTLD_NOW);
                }
                printf("Realisation was changed.\n");
                printf("Input your command: ");
                scanf("%d", &com);
                break;
            case 1:
                printf("input a and b: ");
                scanf("%d %d", &a, &b);
                int (*func_primeCount)(int, int);
                func_primeCount = (int (*)(int, int))dlsym(library, name1);

                if (!func_primeCount) {
                    fprintf(stderr, "PrimeCount error: %s\n", dlerror());
                    return 1;
                }

                printf("PrimeCount result: %d\n", func_primeCount(a, b));
                printf("Input your command: ");
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

                void (*func_sort)(int *, int);
                func_sort = (void (*)(int *, int))dlsym(library, name2);

                if (!func_sort) {
                    fprintf(stderr, "sort function error: %s\n", dlerror());
                    return 1;
                }

                func_sort(array, size);

                printf("Sorted array: ");
                for (int i = 0; i < size; ++i) {
                    printf("%d ", array[i]);
                }
                printf("\n");

                free(array);

                printf("Input your command: ");
                scanf("%d", &com);
                break;
            default:
                printf("Incorrect input\n");
                return 1;
        }
    }

    dlclose(library);

    return 0;
}
