#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int l=0,r=-1;
    int maxlen=0,len=0;
    int num_flips=0,n=nums.size();
    for(int i=0;i<n;i++){
        r=i;
        if(nums[r]==1) len++;
        else{
            if(num_flips<k){
                len++;
                num_flips++;
            }
            else{
                while(num_flips>k){
                    if(nums[l]==0) num_flips--;
                    l++;
                    len--;
                }
            }
        }
        maxlen=max(maxlen,len);
    }
    return maxlen;
}