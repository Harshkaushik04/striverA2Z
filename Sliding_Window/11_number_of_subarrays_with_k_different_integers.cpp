#include<bits/stdc++.h>
using namespace std;

int f(vector<int>& nums, int k) {
    unordered_map<int,int> mpp;
    int n=nums.size();
    long long ans=0;
    for(int i=0;i<n;i++){
        if(mpp.find(nums[i])!=mpp.end()) mpp[nums[i]]=i;
        else{
            mpp[nums[i]]=i;
            if(mpp.size()==k+1){
                int mini=0,miniIndex=-1;
                for(auto& p:mpp) {
                    if(mini>=p.second){
                        mini=p.second;
                        miniIndex=p.first;
                    }
                }
                mpp.erase(miniIndex);
            }
        }
        if(mpp.size()==k){
            int mini=0;
            for(auto& p:mpp) {
                if(mini>=p.second) mini=p.second;
            }
            ans+=(mini+1);
        }
    }
    return ans;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return f(nums,k)-f(nums,k+1);
}