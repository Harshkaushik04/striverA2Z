#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int singleNumber(vector<int>& nums) {
    int numsSize=nums.size();
    unordered_map<int,int> mpp;
    bool found=false;
    for(int i=0;i<numsSize;i++){
        found=false;
        for(pair<int,int> element:mpp){
            if(element.first==nums[i]){
                found=true;
                break;
            }
        }
        if(found){
            mpp[nums[i]]+=1;
        }
        else{
            mpp[nums[i]]=1;
        }
    }
    for(pair<int,int> element:mpp){
        if(element.second==1){
            return element.first;
        }
    }
}