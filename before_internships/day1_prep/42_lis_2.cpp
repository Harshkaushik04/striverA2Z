#include<bits/stdc++.h>
using namespace std;
//not done
int lengthOfLIS(vector<int>& nums, int k) {
    vector<int> vec={nums[0]};
    int n=nums.size();
    for(int i=1;i<n;i++){
        if(nums[i]>vec[vec.size()-1]){
            if(nums[i]-vec[vec.size()-1]<=k) vec.emplace_back(nums[i]);
        } 
        else{
            vector<int>::iterator it=lower_bound(vec.begin(),vec.end(),nums[i]);
            if(vec[it-vec.begin()]-nums[i]<=k) vec[it-vec.begin()]=nums[i];
        }
    }
    cout<<"vec:"<<endl;
    for(int i=0;i<vec.size();i++) cout<<vec[i]<<" ";
    cout<<endl;
    return vec.size();
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n,-1);
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<lengthOfLIS(nums,k)<<endl;
    return 0;
}