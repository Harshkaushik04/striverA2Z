#include<iostream>
#include<vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int numsSize=nums.size();
    int low=0,high=numsSize-1,mid=(low+high)/2;
    bool flag=false;
    if(numsSize==1){
        return 0;
    }
    while(true){
        if(mid!=0 && mid!=numsSize-1){
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid+1]>=nums[mid]){
                low=mid+1;
                mid=(low+high)/2;
            }
            else if(nums[mid-1]>=nums[mid]){
                high=mid-1;
                mid=(low+high)/2;
            }
        }
        else if(mid==0){
            if(nums[mid]>nums[mid+1]){
                return mid;
            }
            if(low==high){
                flag=true;
            }
            low=mid+1;
            mid=(low+high)/2;
        }
        else{
            if(nums[mid]>nums[mid-1]){
                return mid;
            }
            if(low==high){
                flag=true;
            }
            high=mid-1;
            mid=(low+high)/2;
        }
        if(flag){
            break;
        }
    }
    return -1;
}

int main(){
    return 0;
}