#include<bits/stdc++.h>
using namespace std;

int f(vector<int>& nums, int k) {
    unordered_map<int,int> mpp;
    int n=nums.size();
    long long ans=0;
    int l=0,r=0;
    for(int i=0;i<n;i++){
        r=i;
        if(mpp.find(nums[i])!=mpp.end()) mpp[nums[i]]++;
        else mpp[nums[i]]=1;
        if(mpp.size()==k+1){
            while(true){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) {
                    mpp.erase(nums[l]);
                    l++;
                    break;
                }
                l++;
            }
            while(true){
                if(mpp[nums[l]]>1){
                    mpp[nums[l]]--;
                    l++;
                }
                else break;
            }
            ans+=(l+1);
        }
        else if(mpp.size()==k){
            while(true){
                if(mpp[nums[l]]>1){
                    mpp[nums[l]]--;
                    l++;
                }
                else break;
            }
            ans+=(l+1);
        }
    }
    return ans;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return f(nums,k)-f(nums,k+1);
}
