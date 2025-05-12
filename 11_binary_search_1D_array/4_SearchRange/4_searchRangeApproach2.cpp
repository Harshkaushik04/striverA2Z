#include<iostream>
#include<vector>

using namespace std;

int findFloor(vector<int>& arr, int k) {
    int low=0,high=arr.size()-1,mid=(low+high)/2;
    int ans=arr.size();
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]<=k){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(ans==arr.size()){
        return -1;
    }
    else if(arr[ans]<=k){
        return ans;
    }
    else{
        return -1;
    }
}

int findCeiling(vector<int>& arr,int k){
    int low=0,high=arr.size()-1,mid=(low+high)/2;
    int ans=arr.size();
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]>=k){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(ans==arr.size()){
        return -1;
    }
    else if(arr[ans]>=k){
        return ans;
    }
    else{
        return -1;
    }
}

vector<int> searchRange(vector<int>& nums, int target) {
   int ceiling=findCeiling(nums,target);
   int floor=findFloor(nums,target);
   if(nums.size()==0){
    return {-1,-1};
   }
   if(ceiling!=-1 && floor!=-1){
    if(nums[ceiling]!=target){
    ceiling=-1;
   }
   if(nums[floor]!=target){
    floor=-1;
   }
   }
   else{
    return {-1,-1};
   }
   return {ceiling,floor};
}