#include<stdio.h>

int SMALLEST(int arr[],int i,int n){
    int SMALL=arr[i];
    int pos=i;

    for (int j=i+1;j<n;j++){
        if(arr[j]<SMALL){
            SMALL=arr[j];
            pos=j;
        }
    }

    return pos;
}

int SELECTION_SORT(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int pos=SMALLEST(arr,i,n);

        if(pos!=i){
            int temp=arr[i];
            arr[i]=arr[pos];
            arr[pos]=temp;
        }
    }
}

int main(){
    int arr[]={64,35,25,12,22,11,90};
    int n=sizeof(arr)/sizeof(arr[0]);

    SELECTION_SORT(arr,n);

    printf("\nSorted Array: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    return 0;
}
