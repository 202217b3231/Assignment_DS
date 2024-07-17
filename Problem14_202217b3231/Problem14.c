#include<stdio.h>

#define MAX_NODES 15

char tree[]={'\0','D','A','F','E','B','R','T','G','Q','\0','\0','V','\0','J','L'};

int get_left_child(int index){
    int left_index = 2*index;
    if (left_index <= MAX_NODES && tree[left_index]!= '\0')
        return left_index;
    return -1;
}

int get_right_child(int index){
    int right_index = 2*index + 1;
    if (right_index <= MAX_NODES && tree[right_index]!= '\0')
        return right_index;
    return -1;
}

void preorder(int index){
    if(index != -1 && tree[index] != '\0'){
        printf(" %c ", tree[index]);
        preorder(get_left_child(index));
        preorder(get_right_child(index));
    }
}

void postorder(int index){
    if(index != -1 && tree[index] != '\0'){
        postorder(get_left_child(index));
        postorder(get_right_child(index));
        printf(" %c ", tree[index]);
    }
}

void inorder(int index){
    if(index != -1 && tree[index] != '\0'){
        inorder(get_left_child(index));
        printf(" %c ", tree[index]);
        inorder(get_right_child(index));
    }
}

int main(){
    printf("\nPreorder:\n");
    preorder(1);
    printf("\nPostorder:\n");
    postorder(1);
    printf("\nInorder:\n");
    inorder(1);
    printf("\n");

    return 0;
}
