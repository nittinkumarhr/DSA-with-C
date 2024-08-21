// #NOTE -  Selection sort is a simple sorting algorithm. This sorting algorithm is an in-place comparison-based algorithm in which the list is divided into two parts, 
// the sorted part at the left end and the unsorted part at the right end. Initially, the sorted part is empty and the unsorted part is the entire list.
//NOTE - The smallest element is selected from the unsorted array and swapped with the leftmost element, and that element becomes a part of the sorted array.
//NOTE - Time Complexity - O(n^2) Space complexity - O(1)

#include <stdio.h>
void main(){
    int arr[]={12,34,11,44,6,66,3,78};
    int r,q;
    printf("\nEnter the Arrange :");
    scanf("%d",&r);
    printf("Enter the items in the Array  :\n");
    for (q=0;q<r;q++){
        scanf("%d",&arr[q]);
    }
    SelectionSortToAscending(arr,r);
    SelectionSortToDescending(arr,r);
}
int SelectionSortToAscending(int arr[],int r){
    int i,j,temp,min,pivot;
    for (i=0;i<r-1;i++){
        min=arr[i];
        pivot=i;
        for (j=i+1;j<r;j++){
            if (min>arr[j]){
                min=arr[j];
                pivot=j;

            }
        }
        temp=arr[i];
        arr[i]=arr[pivot];
        arr[pivot]=temp;
    }

    printf("After sorting The Array To Ascending Order :\n");
    for(i=0;i<r;i++){
        printf("%d ",arr[i]);
    }
    
}
int SelectionSortToDescending(int arr[],int r){
    int i,j,temp,min,pivot;
    for (i=0;i<r-1;i++){
        min=arr[i];
        pivot=i;
        for (j=i+1;j<r;j++){
            if (min<arr[j]){
                min=arr[j];
                pivot=j;

            }
        }
        temp=arr[i];
        arr[i]=arr[pivot];
        arr[pivot]=temp;
    }
    printf("\n After sorting The Array TO descending Order :\n");
    for(i=0;i<r;i++){
        printf("%d ",arr[i]);
    }
}