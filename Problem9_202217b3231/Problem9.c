#include<stdio.h>

void insertion_sort(int a[],int n){
    int key;

    for (int i=1;i<n;i++){
        key=a[i];
        int j=i-1;

        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void print_array(int a[],int n){
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main(){
    int a[]={12,31,25,8,32,17};
    int n=sizeof(a)/sizeof(a[0]);

    printf("\nBefore sorting: ");
    print_array(a,n);

    printf("\nAfter sorting: ");
    insertion_sort(a,n);
    print_array(a,n);

    return 0;
}
