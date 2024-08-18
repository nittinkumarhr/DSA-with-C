//NOTE -  Sorting  is a technical term used in computer science to describe the process of arranging a list of items in a particular order.
//  The order can be ascending (from smallest to largest) or descending (from largest to smallest).
//NOTE - Time Complexity  of Bubble Sort is O(n^2) where n is the number of elements in the array.
//NOTE -  Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.

#include <stdio.h>
int main(){
    int arr[100],r,l;
    printf("Enter the range of the Unsorted array: \n");
    scanf("%d",&r);
    printf("Enter the elements of the Unsorted array: \n");
    for (l=0;l<r;l++){
        scanf("%d",&arr[l]);
    }
    SortingToAscending(arr,r);
    SortingToDescending(arr,r);
}
int SortingToAscending(int arr[100], int r){
    printf("Sorting the Ascending Order using Bubble Sort \n ");
    int i,j,temp;
    for (i=0;i<r;i++){
        for(j=0;j<r-1;j++){
            if (arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;

            }
        }
    }
    printf("Sorted  Array:\n");
    for (i=0;i<r;i++){
        printf("%d\n",arr[i]);
    }
}

int SortingToDescending(int arr[10],int r){
    printf("\n Sorting the Descending  Order using Bubble Sort \n");
    int i,j,temp;
    for (i=0;i<r;i++){
        for(j=0;j<r-1;j++){
            if (arr[j]<arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;

            }
        }
    }
    printf("Sorted  Array:\n");
    for (i=0;i<r;i++){
        printf("%d\n",arr[i]);
    }
}
