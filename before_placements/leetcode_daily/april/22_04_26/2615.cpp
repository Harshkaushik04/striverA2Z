#include<bits/stdc++.h>
using namespace std;

vector<long long> distance(vector<int>& nums) {
    int n=nums.size();
    unordered_map<int,vector<int>> mpp;
    unordered_map<int,long long> sum_mpp;
    unordered_map<int,vector<long long>> suffix_mpp;
    vector<int> index_mpp(n,0);
    for(int i=0;i<n;i++){
        mpp[nums[i]].emplace_back(i);
        index_mpp[i]=mpp[nums[i]].size()-1;
        if(sum_mpp.find(nums[i])!=sum_mpp.end()) sum_mpp[nums[i]]+=i;
        else sum_mpp[nums[i]]=i;
    }        
    for(const pair<int,vector<int>>& p:mpp){
        int m=p.second.size();
        long long temp=0;
        vector<long long> suffix_sum(m,0);
        for(int i=m-1;i>=0;i--){
            temp+=p.second[i];
            suffix_sum[i]=temp;
        }
        suffix_mpp[p.first]=suffix_sum;
    }
    vector<long long> ans(n,0);
    for(int i=0;i<n;i++){
        ans[i]=(2*index_mpp[i]-mpp[nums[i]].size()+2)*i+sum_mpp[nums[i]]+2*(suffix_mpp[nums[i]][index_mpp[i]]-i);
    }
    return ans;
}