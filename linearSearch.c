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