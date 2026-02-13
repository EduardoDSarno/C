#include <stdio.h>
int removeElement(int* nums, int numsSize, int val);


int main(){

    int nums[] = {3, 2, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 3;

    int newSize = removeElement(nums, numsSize, val);

    printf("\nNew array: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\nNew size returned: %d\n", newSize);
    return 0;

}

int removeElement(int* nums, int numsSize, int val) 
{
    int k = 0; // write element index

    for (int i = 0; i < numsSize; i++){
        
        if (nums[i] != val){

            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}