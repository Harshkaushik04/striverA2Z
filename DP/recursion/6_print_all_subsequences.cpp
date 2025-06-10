#include<bits/stdc++.h>
using namespace std;

void print_arr(vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<endl;
}

void print_all_subsequences(int index,vector<int>& ans,vector<int>& arr,int n){
    if(index>=n){
        print_arr(ans);
        return;
    }
    ans.emplace_back(arr[index]); //take
    print_all_subsequences(index+1,ans,arr,n);
    ans.pop_back(); //not take
    print_all_subsequences(index+1,ans,arr,n);
}