#include<bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    int first_sum=0;https://zed.dev/
    int total_sum=0;
    for(int i=0;i<n;i++){
        first_sum+=(i*nums[i]);
        total_sum+=nums[i];
    }
    int maxi=first_sum;
    int sum=first_sum;
    for(int i=1;i<n;i++){
        sum=sum-total_sum+n*nums[i-1];
        maxi=max(maxi,sum);
    }
    return maxi;
}

int main(){
    return 0;
}