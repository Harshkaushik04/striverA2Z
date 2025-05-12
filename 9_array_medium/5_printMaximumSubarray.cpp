#include<iostream>
#include<vector>
using namespace std;

//Kadane algorithm
int maxSubArray(vector<int>& nums) {
    int numsSize=nums.size();
    int sum=0;
    int maxi=INT32_MIN;
    int temp1=0,temp2=0;
    pair<int,int> maxPair;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
        if(maxi<sum){
            maxPair={temp1,temp2};
            maxi=sum;
        }
        if(sum<0){
            sum=0;
            temp1=i+1;
            temp2=i;
        }
        if(temp2<numsSize-1){
            temp2++;
        }
    }
    for(int i=maxPair.first;i<=maxPair.second;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return maxi;
}

int main(){
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    int maxi=maxSubArray(arr);
    cout<<"max sum:"<<maxi<<endl;
    return 0;
}