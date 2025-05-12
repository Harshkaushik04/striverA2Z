#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int removeDuplicates(vector<int> nums) {
    unordered_map<int,int> mpp;
    vector<int> keys;
    int numsSize=nums.size();
    bool tempFlag=false;
    for(int i=0;i<numsSize;i++){
        tempFlag=false;
        for(pair<int,int> p:mpp){
            //already a key of mpp
            if(p.first==nums[i]){
                tempFlag=true;
                break;
            }
        }
        //not a key of mpp
        if(!tempFlag){
            mpp[nums[i]]=1;
        }
        else{
            mpp[nums[i]]+=1;
        }
    }
    for(pair<int,int> p:mpp){
        // cout<<p.first<<"->"<<p.second<<endl;
        for(int j=0;j<p.second-1;j++){
            auto it = std::find(nums.begin(), nums.end(), p.first);
        if (it != nums.end()) {
            nums.erase(it);
        }
        }
        // for(int j=0;j<nums.size();j++){
        //     cout<<nums[j]<<" ";
        // }
        // cout<<endl;
    }
    return nums.size();
}

int main(){
    int n=removeDuplicates({1,1,2});
    return 0;
}