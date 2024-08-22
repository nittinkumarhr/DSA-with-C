//NOTE - Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part.
//  Values from the unsorted part are picked and placed at the correct position in the sorted part.
//NOTE - It is checked  if unsorted element GRATER THAN  the sorted elements and then placed the unsorted elements right side of sorted element.
//NOTE - It is checked  if sorted element GRATER THAN  the unsorted elements and then placed the unsorted elements left side of sorted element
// Time Complexity - O(n^2), Space Complexity - O(1)
#include <stdio.h>

int  main(){
    int arr[]={};
    int r,q;
    printf("Enter the Array Size : ");
    scanf("%d",&r);
    printf("\n Enter elements  : \n");
    for (q=0;q<r;q++){
        scanf("%d",&arr[q]);
    }
    InsertionSortToAscending(arr,r);
   
}
int InsertionSortToAscending(int arr[],int r){
     int i,j,temp;
     
    for (i=0;i<r;i++){
        temp=arr[i];
        for(j=i-1;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }

        }
        arr[j+1]=temp;
    }
    printf("\n After sorting Array :\n");
    for(i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
}