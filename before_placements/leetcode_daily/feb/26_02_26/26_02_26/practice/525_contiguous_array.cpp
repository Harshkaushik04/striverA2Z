#include<bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums) {
    int len=nums.size();
    unordered_map<int,int> modified_prefix_sum;
    int temp=0;
    unordered_map<int,int> mpp;
    mpp[1]=1;
    mpp[0]=-1;
    int maxi=0;
    for(int i=0;i<len;i++){
        temp+=mpp[nums[i]];
        if(temp==0){
            maxi=max(maxi,i+1);
        }
        unordered_map<int,int>::iterator found_index=modified_prefix_sum.find(temp);
        if(found_index!=modified_prefix_sum.end()){
            maxi=max(maxi,i-modified_prefix_sum[temp]);
        }
        else{
            modified_prefix_sum[temp]=i;
        }
    }   
    return maxi;
}

int main(){
    vector<int> nums={0,1,0};
    cout<<findMaxLength(nums)<<endl;;
    return 0;
}