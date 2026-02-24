#include<iostream>
#include<vector>

using namespace std;

int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid=(low+high)/2;
    int ans=INT32_MAX;
    int ansIndex=-1;
    while(low<=high){
        if(nums[mid]>=nums[low]){
            if(nums[low]<ans){
                ans=nums[low];
                ansIndex=low;
            }
            low=mid+1;
            mid=(low+high)/2;
        }
        else{
            if(nums[mid]<ans){
                ans=nums[mid];
                ansIndex=mid;
            }
            ansIndex=mid;
            high=mid-1;
            mid=(low+high)/2;
        }
    }
    return ansIndex;
}