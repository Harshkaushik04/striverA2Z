#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    vector<int> numsDuplicate=nums;
    int numsSize=nums.size();
    int updateIndex;
    for(int i=0;i<numsSize;i++){
        updateIndex=i+k;
        while(updateIndex>numsSize-1){
            updateIndex-=numsSize;
        }
        nums[updateIndex]=numsDuplicate[i];
    }
}

int main(){
    return 0;
}
