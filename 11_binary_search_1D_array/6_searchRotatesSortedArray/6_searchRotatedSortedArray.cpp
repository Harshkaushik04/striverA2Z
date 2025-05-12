#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int> arr,int i,int j,int target){
    int low=i,high=j,mid=(i+j)/2;
    cout<<low<<" "<<mid<<" "<<high<<endl;
    while(low<=high){
        if(arr[mid]==target){
            return mid;
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
    return -1;
}

int search(vector<int>& nums, int target) {
    int numsSize=nums.size();
    int low=0,high=numsSize-1,mid=(low+high)/2;
    while(low<=high){
        // cout<<low<<" "<<mid<<" "<<high<<endl;
        //first half is sorted
        if(nums[mid]>=nums[low]){
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
        else{
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
    }
    return -1;
}


int main(){
    vector<int> nums={5,1,3};
    int target=2;
    int searchedIndex=search(nums,target);
    cout<<"searched index:"<<searchedIndex<<endl;
    return 0;
}