#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int num_jump=0;
    int l=0,r=0;
    int temp_r=0;
    int n=nums.size();
    if(n==1) return 0;
    while(true){
        for(int i=l;i<=r;i++){
            if(nums[i]+i>temp_r) temp_r=nums[i]+i;
        }
        num_jump++;
        if(temp_r>=n-1) return num_jump;
        l=r+1;
        r=temp_r;
    }
    return false;
}