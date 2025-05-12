#include<iostream>
#include<vector>
#include<map>
using namespace std;

int majorityElement(vector<int>& nums) {
    int numsSize=nums.size();
    map<int,int> mpp;
    for(int i=0;i<numsSize;i++){
        if(mpp.find(nums[i])!=mpp.end()){
            mpp[nums[i]]+=1;
        }
        else{
            mpp[nums[i]]=1;
        }
    }
    for(auto element:mpp){
        if(element.second>numsSize/2){
            return element.first;
        }
    }
    return -1;
}

int main(){
    return 0;
}