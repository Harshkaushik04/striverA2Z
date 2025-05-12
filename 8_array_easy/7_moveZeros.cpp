#include<iostream>
#include<vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    //2 pointer 
    int index=0,i=0;
    int numsSize=nums.size();
    while(index<numsSize){
        while(nums[index]==0 && index!=numsSize-1){
            if(index<numsSize-1){
                index++;
            }
        }       
        if(index<numsSize){
            swap(nums[index],nums[i]);
            i++;
            index++;
        }
        if(index==numsSize){
            break;
        }
    } 
}