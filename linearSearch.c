//NOTE -What it is: A simple search technique where you check each element in a list, one by one, until you find the target element or reach the end of the list.
// When to use: When the list is small or unsorted.
// How it works:
// Start from the first element.
// Compare it with the target element.
// Move to the next element if they don't match.
// Continue until you find the target or reach the end

//NOTE -  Time Complexity -> Time Complexity of Linear Search is O(n) in all three cases (worst, average and best) as elements can be anywhere.
#include <stdio.h>
int main(){
    printf("Linear Search Program  (Linear Search");
    printf("\n Enter the Array Length : \t");
    int l,item,arr[l],i,search;
    scanf("%d",&l);
    printf("Enter the Array items : \t");
    linearSearch(arr,l,
        search);
   
}
int linearSearch(int arr[],int l,int search ){
    int i ,k ;
     for ( i=0;i<l;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n Enter the Item  You want to search \t ");
    scanf("%d",&search);

    for (i=0;i<l;i++){
        if (arr[i]==search){
            k++;
        }
    }
    if(k==0){
        printf("Number is not find  :%d ",search);
    }
    else{
        printf("number is Find : %d \n",search);
    }
}