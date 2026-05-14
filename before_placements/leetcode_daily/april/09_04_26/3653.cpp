#include<bits/stdc++.h>
using namespace std;

int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int n=nums.size();
    int num_queries=queries.size();
    int MOD=1e9+7;
    for(int i=0;i<num_queries;i++){
        int l=queries[i][0];
        int r=queries[i][1];
        int k=queries[i][2];
        int v=queries[i][3];
        int idx=l;
        while(idx<=r){
            long long temp=(long long) nums[idx]*(long long)v;
            temp%=MOD;
            nums[idx]=temp;
            idx+=k;
        }
    }
    int ans=nums[0];
    for(int i=1;i<n;i++){
        ans^=nums[i];
    }
    return ans;
}