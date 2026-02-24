#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int numsSize=nums.size();
    if(numsSize==0){
        return 0;
    }       
    int lastUnique=nums[0];
    int ans=1;
    for(int i=1;i<numsSize;i++){
        if(lastUnique!=nums[i]){
            lastUnique=nums[i];
            nums[ans]=lastUnique;
            ans++;
        }
    }
    return ans;
}