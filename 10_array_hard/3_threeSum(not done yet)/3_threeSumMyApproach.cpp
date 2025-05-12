#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int numsSize=nums.size();
    map<long,int> mpp;
    mpp[nums[0]]=0;
    int temp;
    for(int k=1;k<numsSize;k++){
        if(mpp.find(target-nums[k])!=mpp.end()){
            temp=mpp[target-nums[k]];
            return {temp,k};
        }
        mpp[nums[k]]=k;
    }
    return {};
}

vector<vector<int>> threeSum(vector<int>& nums) {
    int numsSize=nums.size();
    vector<int> twoSumResult;
    vector<vector<int>> result;
    set<vector<int>> setResult;
    int target;
    int temp,temp1;
    for(int i=0;i<numsSize;i++){
        target=nums[i];
        twoSumResult=twoSum(nums,target);
        if(twoSumResult!=vector<int>()){
            if(target>twoSumResult[0]){
                if(target>twoSumResult[1]){
                    twoSumResult.emplace_back(nums[i]);
                }
                else{
                    temp=twoSumResult[1];
                    twoSumResult[1]=target;
                    twoSumResult.emplace_back(temp);
                }
            }
            else{
                temp=twoSumResult[0];
                twoSumResult[0]=target;
                temp1=twoSumResult[1];
                twoSumResult[1]=temp;
                twoSumResult.emplace_back(temp1);
            }
            result.emplace_back(twoSumResult);
        }
    }
    for(vector<int> element:result){
        setResult.insert(element);
    }
    result=vector<vector<int>>();
    for(vector<int> element:setResult){
        result.emplace_back(element);
    }
    return result;
}