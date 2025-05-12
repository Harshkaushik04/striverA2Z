#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int numsSize=nums.size();
    long long sum=0;
    long long maxi=INT64_MIN;
    for(int i=0;i<numsSize;i++){
        sum=0;
        for(int j=i;j<numsSize;j++){
            sum+=nums[j];
            maxi=max(maxi,sum);
        }
    }
    return maxi;
}

int main(){
    return 0;
}