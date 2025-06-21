#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& sorted_arr,int k){ //return index at which sorted_arr[index]>=k
    int n=sorted_arr.size();
    int low=0,high=n-1;
    int mid=(low+high)/2;
    int ans=-1;

    while(low<=high){
        mid=(low+high)/2;
        if(sorted_arr[mid]>=k){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int lengthOfLIS(vector<int>& nums) {
    vector<int> storage={nums[0]};
    int n=nums.size();
    int index=0,m;
    for(int i=1;i<n;i++){
        m=storage.size();
        if(storage[m-1]<nums[i]){
            storage.emplace_back(nums[i]);
        }
        index=lowerBound(storage,nums[i]);
        storage[index]=nums[i];
    }
    return storage.size();
}