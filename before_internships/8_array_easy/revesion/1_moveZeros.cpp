#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int i=0,n=nums.size();
    for(int index=0;index<n;index++){
        if(nums[index]==0) continue;
        else{
            swap(nums[index],nums[i]);
            i++;
        }
    }
}