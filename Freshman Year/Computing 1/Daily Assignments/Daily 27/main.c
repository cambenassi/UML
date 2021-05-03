#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numElements;
    int* array = NULL;
    
    printf("Please enter the number of elements of your dynamic array: ");
    scanf("%d", &numElements);

    while (numElements < 0)
    {
        printf("Invalid number of elements for array. Enter a valid number ");
        scanf("%d", &numElements);
    }
    
    array = (int*)malloc(numElements * sizeof(int));
    
    for (int i = 0; i < numElements; ++i)
    {
        array[i] = i + 1;
    }
    
    for (int i = numElements - 1; i >= 0; --i)
    {
        printf("Element at index %d : %d\n", i, array[i]);
    }
    printf("***\n");
    for (int i = 0; i < numElements; ++i)
    {
        printf("Element at index %d : %d\n", i, *(array + i));
    }
    
    
    free(array);
    return 0;
}
