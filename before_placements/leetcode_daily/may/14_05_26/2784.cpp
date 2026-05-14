#include<bits/stdc++.h>
using namespace std;

bool isGood(vector<int>& nums) {
    int n=nums.size();
    vector<int> count(n+1,0);
    for(int i=0;i<n;i++){
        if(nums[i]==n-1 && count[nums[i]]>=2) return false;
        else if(nums[i]>n-1 || nums[i]<1) return false;
        else if(nums[i]!=n-1 && count[nums[i]]>=1) return false;
        count[nums[i]]++;
    }
    return true;
}

int main(){
    return 0;
}