#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> result;
    vector<int> positives,negatives;
    int numsSize=nums.size();
    for(int i=0;i<numsSize;i++){
        if(nums[i]>=0){
            positives.emplace_back(nums[i]);
        }
        else{
            negatives.emplace_back(nums[i]);
        }
    }
    for(int i=0;i<numsSize/2;i++){
        result.emplace_back(positives[i]);
        result.emplace_back(negatives[i]);
    }
    return result;
}

int main(){
    return 0;
}
