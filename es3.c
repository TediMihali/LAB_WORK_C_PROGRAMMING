#include<stdio.h>

int main(){
    int i, j;
    int nums[5];
    for(i=0;i<5;i++){
        scanf("%d", &nums[i]);
       
    }
    for(i=0;i<5;i++){
         j=0;
        while(j<nums[i]){
            printf("#");
            j++;
        }
        printf("\n");
    }
}