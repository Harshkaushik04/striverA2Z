#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    // O(k) space complexity
    int numsSize=nums.size();
    k%=numsSize;
    vector<int> tempArr;
    for(int i=0;i<k;i++){
        tempArr.emplace_back(nums[i]);
    }
    for(int i=k;i<numsSize;i++){
        nums[i-k]=nums[i];
    }
    for(int i=0;i<k;i++){
        nums[i-k+numsSize]=tempArr[i];
    }
}

int main(){
    vector<int> arr={1,2,3,4,5};
    rotate(arr,2);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}