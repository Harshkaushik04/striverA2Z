#include<iostream>
#include<vector>

using namespace std;

bool binarySearch(vector<int> arr,int i,int j,int target){
    int low=i,high=j,mid=(i+j)/2;
    cout<<low<<" "<<mid<<" "<<high<<endl;
    while(low<=high){
        if(arr[mid]==target){
            return true;
        }
        else if(arr[mid]>target){
            high=mid-1;
            mid=(low+high)/2;
        }
        else{
            low=mid+1;
            mid=(low+high)/2;
        }
    }
    return false;
}

int search(vector<int>& nums, int target) {
    int numsSize=nums.size();
    int low=0,high=numsSize-1,mid=(low+high)/2;
    while(low<=high){
        cout<<low<<" "<<mid<<" "<<high<<endl;
        //first half is sorted
        if((nums[mid]>nums[low] && nums[mid]>nums[high])|| (nums[mid]=nums[high] && nums[mid]>nums[low])){
            if(target>=nums[low] && target<=nums[mid]){
                return binarySearch(nums,low,mid,target);
            }
            else{
                    //check in second half
                    low=mid+1;
                    mid=(low+high)/2;
                    continue;
                }
        }
        // second half is sorted
        else if((nums[mid]<nums[high] && nums[mid]<nums[low]) || (nums[mid]=nums[low] && nums[mid]<nums[high])){
            if(target>=nums[mid] && target<=nums[high]){
                return binarySearch(nums,mid,high,target);
            }
            else{
                    //check in first half
                    high=mid-1;
                    mid=(low+high)/2;
                    continue;
            }
        }
        else{
            if(nums[low]==target){
                return true;
            }
            high--;
            low++;
        }
    }
    return false;
}


int main(){
    vector<int> nums={1,0,1,1,1};
    int target=0;
    bool ans=search(nums,target);
    cout<<"searched index:"<<ans<<endl;
    return 0;
}