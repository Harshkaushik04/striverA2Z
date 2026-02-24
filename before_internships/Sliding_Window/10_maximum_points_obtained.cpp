#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& arr, int k) {
    int sum=0;
    int n=arr.size();
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    int maxSum=sum;
    for(int i=0;i<k;i++){
        sum-=arr[k-i-1];
        sum+=arr[n-i-1];
        maxSum=max(maxSum,sum);
    }
    return maxSum;
}