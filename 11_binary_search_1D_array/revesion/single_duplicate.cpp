#include<bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n=nums.size();
    int l=0,h=n-1;
    int mid=(l+h)/2;
        while(l<=h){
            if((l-h+1)/2%2==0){
                if(mid-1>=0 && nums[mid-1]==nums[mid]){
                    h=mid-1;
                    mid=(l+h)/2;
                }
                else if(mid+1<n && nums[mid+1]==nums[mid]){
                    l=mid+1;
                    mid=(l+h)/2;
                }
                else return nums[mid];
            }
            else{
                if(mid+1<n && nums[mid+1]==nums[mid]){
                    h=mid-1;
                    mid=(l+h)/2;
                }
                else if(mid-1>=0 && nums[mid-1]==nums[mid]){
                    l=mid+1;
                    mid=(l+h)/2;
                }
                else return nums[mid];
            }
        }
    return -1;
}