#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int numsSize=nums.size();
    bool flag=true;
    int mini=INT32_MAX,miniIndex=-1;
    int tempIndex1=-1;
    if(numsSize==1){
        return;
    }
    //for reverse sorted
    for(int i=numsSize-1;i>0;i--){
        if(nums[i]>nums[i-1]){
            tempIndex1=i-1;
            flag=false;
            break;
        }
    }
    if(flag){
        reverse(nums.begin(),nums.end());
        return;
    }
    //main
    for(int k=tempIndex1+1;k<numsSize;k++){
        if(nums[tempIndex1]<nums[k] && mini>=nums[k]){ // >= so that rightmost element is selected in case of equal elements
            mini=nums[k],miniIndex=k;
        }
    }
    swap(nums[tempIndex1],nums[miniIndex]);
    reverse(nums.begin()+tempIndex1+1,nums.end());
}

int main(){
    return 0;
}