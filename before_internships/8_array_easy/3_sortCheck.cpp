#include<iostream>
#include<vector>

using namespace std;

bool check(vector<int> nums) {
    int numsSize=nums.size();
    bool flag=false;
    int first=nums[0];
    for(int i=0;i<numsSize-1;i++){
        if(nums[i]>nums[i+1] && !flag && nums[i+1]<=first){
            flag=true;
            continue;
        }
        else if(nums[i]>nums[i+1] && flag){
            return false;
        }
        else if(nums[i]>nums[i+1] && nums[i+1]>first){
            return false;
        }
        else if(flag && nums[i+1]>first){
            return false;
        }
    }
    return true;
}

int main(){
    cout<<check({2,1,3,4})<<endl;
    return 0;
}