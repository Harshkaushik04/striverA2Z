#include<bits/stdc++.h>
using namespace std;

int reverse(int m){
    int num_digits=0;
    int num=m;
    while(num!=0){
        num/=10;
        num_digits++;
    }
    long long reversed_number=0;
    num=m;
    for(int i=0;i<num_digits;i++){
        int digit=num/pow(10,num_digits-i-1);
        reversed_number+=(digit*pow(10,i));
        num-=(digit*pow(10,num_digits-i-1));
    }
    if(reversed_number>INT32_MAX) return -1;
    return reversed_number;
}

int minMirrorPairDistance(vector<int>& nums) {
     int n=nums.size();
     unordered_map<int,vector<int>> mpp;
    for(int i=0;i<n;i++){
        mpp[reverse(nums[i])].emplace_back(i);
    }
    int ans=INT32_MAX;
    for(int i=0;i<n;i++){
        if(mpp.find(nums[i])!=mpp.end()){
            int m=mpp[nums[i]].size();
            for(int j=0;j<m;j++){
                if(mpp[nums[i]][j]<i) ans=min(ans,i-mpp[nums[i]][j]);
            }
        } 
        if(ans==1) return ans;
    }
    if(ans==INT32_MAX) return -1;
    return ans;
}