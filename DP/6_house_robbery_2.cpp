#include<bits/stdc++.h>
using namespace std;

//optimal solution
int rob(vector<int>& nums) {
    int n=nums.size();
    int take,not_take;
    int prev=nums[0],prev2=0;
    if(n==1) return nums[0];
    for(int i=1;i<n-1;i++){
        take=nums[i]+prev2;
        not_take=prev;
        prev=max(take,not_take);
        prev2=not_take;
    }
    int ans1=prev;
    prev=nums[1],prev2=0;
    for(int i=2;i<n;i++){
        take=nums[i]+prev2;
        not_take=prev;
        prev=max(take,not_take);
        prev2=not_take;
    }
    int ans2=prev;
    return max(ans1,ans2);
}