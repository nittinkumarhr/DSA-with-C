//NOTE -  Binary Search only apply for shorted array 
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