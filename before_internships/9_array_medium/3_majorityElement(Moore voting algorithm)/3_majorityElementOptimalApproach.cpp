#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int maxi=nums[0];
    int count=1;
    int numsSize=nums.size();
    for(int i=1;i<numsSize;i++){
        if(nums[i]==maxi){
            count++;
        }
        else if(nums[i]!=maxi && count>0){
            count--;
        }
        else{
            maxi=nums[i];
            count=1;
        }
    }
    return maxi;
}

int main(){
    return 0;
}