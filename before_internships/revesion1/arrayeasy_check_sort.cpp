#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> nums) {
    int numsSize=nums.size();
    if(numsSize==0){
        return true;
    }
    int small=nums[0];
    bool flag=false;
    for(int i=0;i<numsSize-1;i++){
        if(!flag && nums[i]>nums[i+1]){
            if(nums[i+1]<=small){
                flag=true;
                continue;
            }
            else{
                return false;
            }
        }
        if((nums[i]>nums[i+1])||(nums[i+1]>small && flag)){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> nums={3,4,5,1,2};
    bool val=check(nums);
    cout<<val<<endl;
    return 0;
}