#include<iostream>
#include<vector>
#include<map>
using namespace std;

//pair is guaranteed
vector<int> twoSum(vector<int>& nums, int target) {
    int numsSize=nums.size();
    map<long,int> mpp;
    mpp[nums[0]]=0;
    int temp;
    for(int k=1;k<numsSize;k++){
        if(mpp.find(target-nums[k])!=mpp.end()){
            temp=mpp[target-nums[k]];
            return {temp,k};
        }
        mpp[nums[k]]=k;
    }
    return {};
}