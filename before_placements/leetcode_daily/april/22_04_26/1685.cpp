#include<bits/stdc++.h>
using namespace std;

vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++) sum+=nums[i];
    vector<int> suffix_sum(n,0);
    int temp=0;
    for(int i=n-1;i>=0;i--){
        temp+=nums[i];
        suffix_sum[i]=temp;
    }   
    vector<int> final_ans(n,0);     
    for(int i=0;i<n;i++){
        final_ans[i]=(2*i-n+2)*nums[i]-sum+2*(suffix_sum[i]-nums[i]);
    }
    return final_ans;
}