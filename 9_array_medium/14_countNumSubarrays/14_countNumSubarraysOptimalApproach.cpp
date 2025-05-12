#include<iostream>
#include<vector>
#include<map>

using namespace std;

void printMap(map<long long,int> mpp){
    for(auto element:mpp){
        cout<<element.first<<"->"<<element.second<<endl;
    }
}

int subarraySum(vector<int>& nums, int k){
    int numsSize=nums.size();
    long long prefixSum=0;
    map<long long,int> mpp={{0,1}}; // prefixsum count
    int result=0;
    for(int j=0;j<numsSize;j++){
        prefixSum+=nums[j];
        if(mpp.find(prefixSum-k)!=mpp.end()){
            result+=mpp[prefixSum-k];
        }
        if(mpp.find(prefixSum)==mpp.end()){
            mpp[prefixSum]=1;
        }
        else{
            mpp[prefixSum]+=1;
        }
    }
    return result;
}

int main(){
    vector<int> nums={1,1,1};
    vector<int>& arrAdd=nums;
    int k=2;
    int num=subarraySum(arrAdd,k);
    cout<<"num:"<<num<<endl;
    return 0;
}