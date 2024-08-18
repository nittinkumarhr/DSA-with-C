//NOTE -  Binary Search only apply for shorted array 
//NOTE - What it is: A more efficient search technique that works on sorted lists by repeatedly dividing the search range in half.
// When to use: When the list is sorted
// How it works:
// Find the middle element of the list.
// Compare it with the target element.
// If the middle element is the target, you're done.
// If the target is smaller, search the left half.
// If the target is larger, search the right half.
// Repeat until you find the target or the search range is empty.

//NOTE -  Binary search Time Complexity->Search O(log n)
#include <stdio.h>
int main(){
    int arr[20]={2,4,6,12,15,21,22,23,24,54,55,65,66,87,88};
    int l=0,r=15;
    int item,m;
    printf("Enter the Item You want to Search : ");
    scanf("%d",&item);
    while (l<=r)
    {

        m=(l+r)/2;
        if (arr[m]==item){
            printf("Number is Find: %d \n",m+1);
            break;
        }
        else if (arr[m]>item)
        {


            r=m-1;
        }
        else if (arr[m]<item)
        {
            l=m+1;
        }
    }
if(l>r){
    printf("Number is not found :%d \n ",item);
}
}