#include<iostream>
#include<vector>

using namespace std;

bool searchInSorted(vector<int> arr, int k) {
    int arrSize=arr.size();
    int left=0;
    int right=arrSize-1;
    int mid=(left+right)/2;
    while(left<=right){
        if(arr[mid]>k){
            right=mid-1;
            mid=(left+right)/2;
        }
        else if(arr[mid]<k){
            left=mid+1;
            mid=(left+right)/2;
        }
        else{
            return true;
        }
    }
    return false;
}