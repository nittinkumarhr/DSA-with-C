#include <stdio.h>
#include <time.h> 
#include <stdlib.h> 
#include <unistd.h>

int compare = 0;
int swap_count = 0;
char mode;

// Function to write data into a file for analysis
int push_data_File(int arr[], double t, int s, int c, int size, char mode) {
    FILE *file = fopen("Data.csv", "a");
    if (file == NULL) {
        printf("Error opening file\n");
        return -1; // Return error if file fails to open
    }
    fprintf(file, "%d,%f,%d,%d,%c\n", size, t, s, c, mode);
    fclose(file);
    return 0; 
}

// Partition function that selects pivot based on user choice
int partition(int arr[], int s, int l, int part) {
    int pivot;
    if (part == 1) {
        pivot = arr[s];  // Starting element as pivot
        mode = 'F';
    } else if (part == 2) {
        if (l % 2 == 0) {
            pivot = arr[(l / 2 + ((l / 2) + 1)) / 2];  
        } else {
            pivot = arr[(l + 1) / 2];  // Middle element as pivot
        }
        mode = 'M';
    } else {
        pivot = arr[l];  // Ending element as pivot
        mode = 'E';
    }

    int count = 0;

    // Count elements smaller than or equal to pivot
    for (int i = s + 1; i <= l; i++) {
        compare++;
        if (arr[i] <= pivot) {
            count++;
        }
    }

    // Place pivot at its correct position
    int pivotIndex = s + count;
    swap_count++;
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[s];
    arr[s] = temp;

    // Sort elements around the pivot
    int i = s, j = l;
    while (i < pivotIndex && j > pivotIndex) {
        // Move left elements
        while (arr[i] <= pivot) {
            i++;
        }
        // Move right elements
        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
           
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            swap_count++;
            i++;
            j--;
        }
        compare += 3;
    }

    return pivotIndex;
}

// QuickSort function
void quickSort(int arr[], int s, int l, int part) {
    if (s >= l) {
        return;
    }

    int p = partition(arr, s, l, part);  // Partition and get pivot index
    quickSort(arr, s, p - 1, part);      // Recursively sort left side
    quickSort(arr, p + 1, l, part);      // Recursively sort right side
}

int main() {
    printf("Enter the size of Array: ");
    int s;
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

    start = clock(); // Start time measurement

    // Perform QuickSort
    quickSort(arr, 0, s - 1, part);  

    end = clock(); // End time measurement

    // Calculate time taken for QuickSort
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    push_data_File(arr, cpu_time_used, swap_count, compare, s, mode);
    printf("Sorted array: ");
    for (int i = 0; i < s; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Log data to file
   

    // Print the time taken for sorting
    printf("Time taken to sort: %f seconds\n", cpu_time_used);

    char any;
    printf("\nDo you want to see the analysis report of this array? Press (Y/N) -> ");
    scanf(" %c", &any);

    if (any == 'Y' || any == 'y') {
        sleep(9);
        system("python analysis.py"); 
    }

    return 0;
}
