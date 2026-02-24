#include<iostream>
#include<vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int numsSize=nums.size();
    int tempIndex1=0,tempIndex2=1;
    vector<int> result(numsSize,0);
    for(int i=0;i<numsSize;i++){
        if(nums[i]>=0){
            result[tempIndex1]=nums[i];
            tempIndex1+=2;
        }
        else{
            result[tempIndex2]=nums[i];
            tempIndex2+=2;
        }
    }
    return result;
}

int main(){
    return 0;
}
