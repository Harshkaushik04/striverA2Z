#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int numsSize=nums.size();
    bool flag=true;
    int mini=INT32_MAX,miniIndex=-1;
    int tempIndex1=-1,tempIndex2=-1;
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
        int left=0,right=numsSize-1;
        while(left<=right){
            swap(nums[left],nums[right]);
            left++,right--;
        }
        return;
    }
    //main
    for(int k=tempIndex1+1;k<numsSize;k++){
        if(nums[tempIndex1]<nums[k] && mini>nums[k]){
            mini=nums[k],miniIndex=k;
        }
    }
    swap(nums[tempIndex1],nums[miniIndex]);
    sort(nums.begin()+tempIndex1+1,nums.end());
}

int main(){
    return 0;
}