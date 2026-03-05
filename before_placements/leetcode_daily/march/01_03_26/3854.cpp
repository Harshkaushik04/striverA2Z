#include<bits/stdc++.h>
using namespace std;
//not solved fully
pair<int,bool> find_max(vector<int>& nums){
    int len=nums.size();
    if(len==0) return pair<int,int>{-1,false};
    int maxi=INT32_MIN;
    bool duplicate_max=false;
    for(int i=0;i<len;i++){
        if(maxi<nums[i]){
            maxi=nums[i];
            duplicate_max=false;
        }
        else if(maxi==nums[i]) duplicate_max=true;
    }
    return pair<int,bool>{maxi,duplicate_max};
}

pair<int,bool> find_min(vector<int>& nums){
    int len=nums.size();
    if(len==0) return pair<int,int>{-1,false};
    int mini=INT32_MAX;
    bool duplicate_min=false;
    for(int i=0;i<len;i++){
        if(mini>nums[i]){
            mini=nums[i];
            duplicate_min=false;
        }
        else if(mini==nums[i]) duplicate_min=true;
    }
    return pair<int,int>{mini,duplicate_min};
}

vector<int> makeParityAlternating(vector<int>& nums) {
    int len=nums.size();
    pair<int,bool> maxi=find_max(nums);
    pair<int,bool> mini=find_min(nums);
    int num_oper=0;
    int num_oper_1=0;
    int num_oper_2=0;
    //odd at even indices
    for(int i=0;i<len;i++){
        if(i%2==0 && nums[i]%2==0){

        }
    }
}