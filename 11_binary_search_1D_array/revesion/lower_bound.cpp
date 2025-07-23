#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr, int target) {
    // code here
    int n=arr.size();
    int l=0,r=n-1;
    int mid=(l+r)/2;
    int ans=1e9;
    int ans_index=-1;
    int temp;
    while(l<=r){
        if(arr[mid]==target){
            ans=target;
            ans_index=mid;
            break;
        }
        else if(arr[mid]>target){
            if(arr[mid]<ans){
                ans=arr[mid];
                ans_index=mid;
            }
            r=mid-1;
            mid=(l+r)/2;
        }
        else if(arr[mid]<target){
            l=mid+1;
            mid=(l+r)/2;
        }
    }
    if(ans_index!=-1){
        temp=ans_index;
        while(temp>0 && arr[temp-1]==arr[temp]) temp--;   
    }
    if(ans==1e9) return n;
    return temp;
}