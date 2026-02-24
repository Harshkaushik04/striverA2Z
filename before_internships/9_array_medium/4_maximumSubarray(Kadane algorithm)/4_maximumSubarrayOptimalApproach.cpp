#include<iostream>
#include<vector>
using namespace std;

//Kadane algorithm
int maxSubArray(vector<int>& nums) {
    int numsSize=nums.size();
    int sum=0;
    int maxi=INT32_MIN;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
        maxi=max(maxi,sum);
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}

int main(){
    return 0;
}