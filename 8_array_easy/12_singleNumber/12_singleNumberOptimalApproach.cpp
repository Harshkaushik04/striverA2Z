#include<iostream>
#include<vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int result=nums[0];
    int numsSize=nums.size();
    for(int i=1;i<numsSize;i++){
        result^=nums[i];
    }
    return result;
}