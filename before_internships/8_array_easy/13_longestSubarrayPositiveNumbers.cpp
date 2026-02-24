#include<iostream>
#include<vector>

using namespace std;

//all positive numbers array
int lenOfLongestSubarr(vector<int>& arr, int k) {
    int left=0;
    int arrSize=arr.size();
    int tempSum=0;
    int maxi=0;
    for(int right=0;right<arrSize;right++){
        tempSum+=arr[right];
        if(tempSum==k){
            maxi=max(maxi,right-left+1);
        }
        else if(tempSum>k){
            tempSum-=arr[left];
            left++;
        }
    }
    return maxi;
}

int main(){
    vector<int> arr={10, 5, 2, 7, 1, 9};
    vector<int>& _arr=arr;
    cout<<lenOfLongestSubarr(_arr,15);
    return 0;
}