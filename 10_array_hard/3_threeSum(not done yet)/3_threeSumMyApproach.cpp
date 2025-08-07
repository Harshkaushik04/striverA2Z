#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> result;
    int j,k;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-2;i++){
        if(i!=0 && nums[i]==nums[i-1]) continue;
        j=i+1,k=n-1;
        while(j<k){
            if(nums[j]+nums[k]>(-nums[i])) k--;
            else if(nums[j]+nums[k]<(-nums[i])) j++;
            else{
                result.emplace_back(vector<int>{nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
        }
    }
    return result;
}