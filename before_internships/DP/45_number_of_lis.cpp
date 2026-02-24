#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n=nums.size();       
    if(n==1) return 1;
    int maxi,ans=0,totalMax=-1;
    vector<int> length(n,1);
    vector<int> count(n,1);
    for(int i=1;i<n;i++){
        maxi=1;
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                if(1+length[j]>maxi){
                    maxi=1+length[j];
                    count[i]=count[j];
                }
                else if(1+length[j]==maxi) count[i]+=count[j];
            }
        }
        if(totalMax<maxi) totalMax=maxi;
        length[i]=maxi;
    }
    for(int i=0;i<n;i++){
        if(length[i]==totalMax) ans+=count[i];
    }
    return ans;
}