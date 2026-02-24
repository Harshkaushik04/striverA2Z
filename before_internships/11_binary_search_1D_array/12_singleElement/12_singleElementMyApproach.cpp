#include<iostream>
#include<vector>

using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int numsSize=nums.size();
    int low=0,high=numsSize-1;
    int mid=(low+high)/2;
    if(numsSize==1){
        return nums[0];
    }
    while(low<=high){
        if(mid!=0 && mid!=numsSize-1){
            if((nums[mid]==nums[mid-1] && mid%2==0) ||(nums[mid]==nums[mid+1] && mid%2==1)){
                high=mid-1;
                mid=(high+low)/2;
                continue;
            }
            if((nums[mid]==nums[mid-1] && mid%2==1)||(nums[mid]==nums[mid+1] && mid%2==0)){
                low=mid+1;
                mid=(low+high)/2;
                continue;
            }
        }
        if(mid==0){
            if(nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
        }
        if(mid==numsSize-1){
            if(nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
        }
        if(mid!=0 && mid!=numsSize-1){
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums={1,2,2,3,3};
    int num=singleNonDuplicate(nums);
    cout<<num<<endl;
    return 0;
}