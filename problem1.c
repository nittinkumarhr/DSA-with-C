#include<stdio.h>

// Bubble Sort for Ascending Order
void BubbleSort(int arr[], int s) {
    int i, j, temp;
    for (i = 0; i < s; i++) {
        for (j = 0; j < s - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Partition function for Quick Sort
int partition(int arr[], int s, int l) {
    int pivot = arr[s];
    int count = 0;

    // Count elements smaller than or equal to pivot
    for (int i = s + 1; i <= l; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    // Place pivot at its correct position
    int pivotIndex = s + count;

 
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[s];
    arr[s] = temp;

    //sort the left and right parts around the pivot
    int i = s, j = l;

    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
       
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        }
    }

    return pivotIndex;
}

// Quick Sort for Descending Order
void quickSort(int arr[], int s, int l) {
    // Base case: if the array has one or no element, it is already sorted
    if (s >= l) {
        return;
    }

    // Partition the array and get the pivot index
    int p = partition(arr, s, l);

    // Recursively sort the left and right subarrays
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, l);
}







int main() {
    printf("\n*****  problem - 1 (Sorting the array Ascending order using Bubble sort and Descending order using Quick sort) ****************\n");
    
    printf("Enter the size of Array:\n");
    int s, choice;
    scanf("%d", &s);

  
    int arr[s];

    printf("Enter elements of array:\n");
    for (int i = 0; i < s; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nIf you want to sort the array:\n Ascending order -> press 1\n Descending order -> press 2\n");
    scanf("%d", &choice);

    if (choice == 1) {
       
        BubbleSort(arr, s);
        printf("\nSorted array in Ascending order is:\n");
        for (int i = 0; i < s; i++) {
            printf("%d ", arr[i]);
        }
    } else if (choice == 2) {

        quickSort(arr, 0, s - 1);
        printf("\nSorted array in Descending order is:\n");
        for (int i = s - 1; i >= 0; i--) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("Invalid choice. Please choose 1 or 2.");
    }

    printf("\n");
    return 0;
}
