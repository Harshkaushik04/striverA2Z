#include<iostream>
#include<vector>

using namespace std;



int missingNumber(vector<int>& nums) {
    int numsSize=nums.size();
    int sum=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
    }
    return (numsSize+1)*numsSize/2-sum;
}