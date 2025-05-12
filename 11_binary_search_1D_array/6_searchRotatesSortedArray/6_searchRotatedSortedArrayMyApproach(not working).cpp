#include<iostream>
#include<vector>

using namespace std;
//not working
int findLowestIndex(vector<int>& nums,int target){
    int low=0,high=nums.size()-1,mid=(low+high)/2;
    int ans=0;
    while(low<=high){
        if(nums[mid]>=nums[0]){
            low=mid+1;
            mid=(low+high)/2;
        }
        else{
            high=mid-1;
            ans=mid;
            mid=(low+high)/2;
        }
        if(low==high){
            return ans;
        }
    }
    return ans;
}

int search(vector<int>& nums, int target) {
    int numsSize=nums.size();
    int lowestIndex=findLowestIndex(nums,target);
    int low,mid,high;
    int imaginaryLow=0,imaginaryHigh=nums.size()-1,imaginaryMid=(imaginaryLow+imaginaryHigh)/2;
    if(numsSize>2){
        low=(imaginaryLow+lowestIndex-1)%(numsSize-1),high=(imaginaryHigh+lowestIndex-1)%(numsSize-1);
        imaginaryMid=(imaginaryLow+imaginaryHigh)/2;
        mid=(imaginaryMid+lowestIndex-1)%(numsSize-1);
    }
    else if(numsSize==1){
        if(nums[0]==target){
            return 0;
        }
        else{
            return -1;
        }
    }
    else if(numsSize==2){
        if(nums[0]==target){
            return 0;
        }
        else if(nums[1]==target){
            return 1;
        }
        else{
            return -1;
        }
    }
    else{
        return -1;
    }
    while(imaginaryLow<=imaginaryHigh){
        // cout<<low<<" "<<mid<<" "<<high<<endl;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            imaginaryHigh=imaginaryMid-1;
            low=(imaginaryLow+lowestIndex-1)%(numsSize-1),high=(imaginaryHigh+lowestIndex-1)%(numsSize-1);
            imaginaryMid=(imaginaryLow+imaginaryHigh)/2;
            mid=(imaginaryMid+lowestIndex-1)%(numsSize-1);

        }
        else{
            imaginaryLow=imaginaryMid+1;
            low=(imaginaryLow+lowestIndex-1)%(numsSize-1),high=(imaginaryHigh+lowestIndex-1)%(numsSize-1);
            imaginaryMid=(imaginaryLow+imaginaryHigh)/2;
            mid=(imaginaryMid+lowestIndex-1)%(numsSize-1);
        }
    }
    return -1;
}


int main(){
    vector<int> nums={1,3};
    int target=3;
    int searchedIndex=search(nums,target);
    cout<<"searched index:"<<searchedIndex<<endl;
    return 0;
}