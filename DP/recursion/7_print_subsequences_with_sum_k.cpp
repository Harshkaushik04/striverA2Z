#include<bits/stdc++.h>
using namespace std;

void print_arr(vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<endl;
}


void print_subsequences_with_sum_k(int n,int index,vector<int>& arr,vector<int>& ans,int sum,int k){
    if(index>=n){
        if(sum==k){
            print_arr(ans);
        }
        return;
    }
    ans.emplace_back(arr[index]);
    sum+=arr[index];
    print_subsequences_with_sum_k(n,index+1,arr,ans,sum,k);
    sum-=arr[index];
    ans.pop_back();
    print_subsequences_with_sum_k(n,index+1,arr,ans,sum,k);
}