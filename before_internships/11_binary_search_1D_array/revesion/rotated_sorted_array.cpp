#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int target) {
    int n=arr.size();
    int l=0,h=n-1;
    int mid=(l+h)/2;
    while(l<=h){
        if(arr[mid]==target) return mid;
        else if(arr[h]>=arr[mid]){
            if(target==arr[h]) return h;
            else if(target<arr[h] && target>arr[mid]){
                l=mid+1;
                mid=(l+h)/2;
            }
            else if(target>arr[h] || target<arr[mid]){
                h=mid-1;
                mid=(l+h)/2;
            }
        }
        else if(arr[h]<arr[mid]){
            if(target==arr[h]) return h;
            else if(target<arr[mid] && target>arr[h]){
                h=mid-1;
                mid=(l+h)/2;
            }
            else if(target>arr[mid] || target<arr[h]){
                l=mid+1;
                mid=(l+h)/2;
            }
        }
    }
    return -1;
}