#include <stdio.h>

int linearSearch(int arr[], int n, int target){
    for(int i=0; i<n ; i++){
        if ( arr[i]==target)
            return i;
    }
    return -1;
}

int main(){
    int a[] = {10,2,8,5,17};
    int n = sizeof(a)/sizeof(a[0]);
    int target = 8;

    printf("\nEnter no. you want to search: ");
    scanf("%d",&target);

    int result = linearSearch(a,n,target);

    if(result == -1)
        printf("\nElement not found in array");
    else
        printf("\nElement found at index: %d", result);

    return 0;
}
