#include <stdio.h>
#include <time.h> 



int partition(int arr[], int s, int l, int part) {
    int pivot;
    if (part == 1) {
        pivot = arr[s];  // Starting element as pivot
    } else if (part == 2) {
        pivot = arr[s + (l - s) / 2];  // Middle element as pivot
    } else {
        pivot = arr[l];  // Ending element as pivot
    }

    int count = 0;

    // Count elements smaller than or equal to pivot
    for (int i = s + 1; i <= l; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    // Place pivot at its correct position
    int pivotIndex = s + count;

    // Swap pivot with the element at the pivotIndex
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[s];
    arr[s] = temp;

    // Now sort the left and right parts around the pivot
    int i = s, j = l;

    while (i < pivotIndex && j > pivotIndex) {
        // Compare and move the left-side elements
        while (arr[i] <= pivot) {
            i++;
        }
        // Compare and move the right-side elements
        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            // Swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int l, int part) {
    // Base case: if the array has one or no element, it is already sorted
    if (s >= l) {
        return;
    }

    // Partition the array and get the pivot index
    int p = partition(arr, s, l, part);

    // Recursively sort the left and right subarrays
    quickSort(arr, s, p - 1, part);
    quickSort(arr, p + 1, l, part);
}

int main() {
    printf("Enter the size of Array:\n");
    int s, choice;
    scanf("%d", &s);
    int arr[s];
    printf("Enter elements of array:\n");
    for (int i = 0; i < s; i++) {
        scanf("%d", &arr[i]);
    }
    
    int part;
    printf("Using QuickSort. Which element is chosen as a Pivot?\n1. Starting Element (Press 1)\n2. Middle Element (Press 2)\n3. End Element (Press 3)\n");
    scanf("%d", &part);

    // Measure time
    clock_t start, end;
    double cpu_time_used;

    // Get the start time
    start = clock();

    // Perform QuickSort
    quickSort(arr, 0, s - 1, part);  // `s-1` for correct bounds

    // Get the end time
    end = clock();

    // Calculate total time taken by QuickSort
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < s; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Print the time taken
    printf("Time taken to sort: %f seconds\n", cpu_time_used);

    return 0;
}
