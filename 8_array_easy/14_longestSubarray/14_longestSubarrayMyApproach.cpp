#include<iostream>
#include<vector>

using namespace std;

long long sum(vector<int> arr,int i,int j){
    long long result=0;
    for(int k=i;k<=j;k++){
        result+=arr[k];
    }
    return result;
}
//it is guaranteed that valid subarray exists
int lenOfLongestSubarr(vector<int>& arr, int k) {
    int arrSize=arr.size();
    long long temp;
    for(int length=arrSize;length>=1;length--){
        for(int start=0;start<arrSize-length+1;start++){
            temp=sum(arr,start,start+length-1);
            if(temp==k){
                return length;
            }
        }
    }
}

int main(){
    return 0;
}