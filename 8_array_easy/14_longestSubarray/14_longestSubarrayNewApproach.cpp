#include<iostream>
#include<vector>

using namespace std;

//it is guaranteed that valid subarray exists
int lenOfLongestSubarr(vector<int>& arr, int k) {
    int arrSize=arr.size();
    long long temp;
    int maxi=0;
    for(int i=0;i<arrSize;i++){
        temp=arr[i];
        for(int j=i;j<arrSize;j++){
            if(i!=j){
                temp+=arr[j];
            }
            if(temp==k){
                maxi=max(maxi,j-i+1);
            }
        }
    }
    return maxi;
}

int main(){
    return 0;
}