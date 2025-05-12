#include<iostream>
#include<vector>

using namespace std;

int findFirstOccurence(vector<int>& nums,int target){
    int low=0,high=nums.size()-1,mid=(low+high)/2;
    int targetIndex=-1;
    while(true){
        if(low>high){
            return targetIndex;
        }
        if(target==nums[mid]){
            targetIndex=mid,high=mid-1;
            mid=(low+high)/2;
        }
        else if(target>nums[mid]){
            low=mid+1;
            mid=(low+high)/2;
        }
        else{
            high=mid-1;
            mid=(low+high)/2;
        }
    }
}

int findSecondOccurence(vector<int>& nums,int target){
    int low=0,high=nums.size()-1,mid=(low+high)/2;
    int targetIndex=-1;
    while(true){
        if(low>high){
            return targetIndex;
        }
        if(target==nums[mid]){
            targetIndex=mid,low=mid+1;
            mid=(low+high)/2;
        }
        else if(target>nums[mid]){
            low=mid+1;
            mid=(low+high)/2;
        }
        else{
            high=mid-1;
            mid=(low+high)/2;
        }
    }
}

vector<int> searchRange(vector<int>& nums, int target) {
    return {findFirstOccurence(nums,target),findSecondOccurence(nums,target)};
}