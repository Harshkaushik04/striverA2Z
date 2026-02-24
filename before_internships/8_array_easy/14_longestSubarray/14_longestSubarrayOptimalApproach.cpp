#include<iostream>
#include<vector>
#include<map>

using namespace std;

//it is guaranteed that valid subarray exists
int lenOfLongestSubarr(vector<int>& arr, int k) {
    int arrSize=arr.size();
    long long prefixSum=0;
    int maxi=0;
    int tempIndex;
    map<long long,int> mpp;
    for(int i=0;i<arrSize;i++){
        prefixSum+=arr[i];
        if(mpp.find(prefixSum)==mpp.end()){
            mpp[prefixSum]=i;
        }
        if(prefixSum==k){
            maxi=max(maxi,i+1);
        }
        if(mpp.find(prefixSum-k)!=mpp.end()){
            tempIndex=mpp[prefixSum-k];
            maxi=max(maxi,i-tempIndex);
        }
        // cout<<prefixSum<<endl;
    }
    if(prefixSum==k){
        return arrSize;
    }
    return maxi;
}

int main(){
    // vector<int> arr={8,18,8,18};
    // vector<int>& arrAdd=arr;
    // int k=26;
    // int len=lenOfLongestSubarr(arrAdd,k);
    // cout<<"len:"<<len<<endl;
    return 0;
}