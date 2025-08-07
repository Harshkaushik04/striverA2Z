#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int sum=0,maxi=INT32_MIN;
    int n=nums.size();
    for(int i=0;i<n;i++){
        sum+=nums[i];
        maxi=max(maxi,sum);
        if(sum<0) sum=0;
    }
    return maxi;
}