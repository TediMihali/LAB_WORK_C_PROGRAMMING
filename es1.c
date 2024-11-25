#include<stdio.h>

int main(){
    int i;
    int j = 0;
    int nums[10];
    int num;
    for(i=0; i<10; i++){
        scanf("%d", &num);
        if(num > 6 && num < 15){
            nums[j] = num;
            j++;
        }
    }

    for(i=0; i<sizeof(nums)/sizeof(int); i++){
        printf("%d", nums[i]);
    }
    return 0;
}