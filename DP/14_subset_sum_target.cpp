#include<bits/stdc++.h>
using namespace std;

// bool isSubArraySum(vector<int>& arr, int sum) {
//     // code here
//     int n=arr.size();
//     for(int i=0;i<n;i++){
//         if(arr[i]==sum) return true;
//     }
//     vector<int> last=arr;
//     vector<int> current(n,-1);
//     int temp;
//     for(int size=2;size<=n;size++){
//         for(int start=0;start<n-size+1;start++){
//             temp=last[start]+arr[start+size-1];
//             if(temp==sum) return true;
//             current[start]=temp;
//         }
//         last=current;
//     }
//     return false;
// }

// use memoization like this in other problems too(have implemented differently with checking index-1 stuff)
bool isSubsetSum(vector<int>& arr, int sum) {
    // code here
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    return f(arr,dp,n-1,sum);
}
//dp---> -1 for not set
//dp--->  1 for true
//dp--->  0 for false
bool f(vector<int>& arr,vector<vector<int>>& dp,int index,int target){
    if(target==0) return true;
    if(index==0) return(arr[0]==target);
    if(dp[index][target]!=-1) return dp[index][target];
    bool not_take=f(arr,dp,index-1,target);
    bool take=false;
    if(target>=arr[index]){
        take=f(arr,dp,index-1,target-arr[index]);
    }
    dp[index][target]=(take||not_take);
    return dp[index][target];
}