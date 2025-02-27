#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 5;
    int *arr = (int*) malloc(size * sizeof(int));
    int i;

    for(i = 0; i < size; i++) {
        printf("Enter the element T[%d] = ", i + 1); 
        scanf("%d", &arr[i]);
    }

    // Resize the array
    size = 10;
    arr = (int*) realloc(arr, size * sizeof(int));

    for(i = 5; i < size; i++) {
        printf("Enter the element T[%d] = ", i + 1);
        scanf("%d", arr + i);
    }

    printf("Array after resizing:\n");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);


    
    printf("\n");
 /*
    int P;
    printf("Enter the position you want to delete: ");
    scanf("%d", &P);

    if (P >= 1 && P <= size) {
        for(int i = P - 1; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;

        printf("Array after deletion at position %d:\n", P);
        for(i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Invalid position entered!\n");
    }
  */
    free(arr);
    
    return 0;
}




  