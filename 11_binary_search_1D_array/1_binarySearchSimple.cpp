#include<iostream>
#include<vector>

using namespace std;

//returns index
int search(vector<int>& nums, int target) {
    int low=0,high=nums.size()-1,mid=(low+high)/2;
    while(true){
        if(low>high){
            return -1;
        }
        if(target==nums[mid]){
            return mid;
        }
        else if(target>nums[mid]){
            low=mid+1;
            mid=(low+high)/2;
        }
        else{
            high=mid-1;
            mid=(low+high)/2;
        }
    }
}

int main(){
    return 0;
}