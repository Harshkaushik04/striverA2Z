#include<bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    // code here
    int n=val.size();
    vector<int> dp(W+1,-1);
    vector<int> prev(W+1,-1);
    for(int i=0;i<=W;i++) prev[i]=0;
    for(int i=n-1;i>=0;i--){
        dp[0]=0;
        for(int j=0;j<=W;j++){
            int take=0,not_take=0;
            if(j>=wt[i]) take=prev[j-wt[i]]+val[i];
            not_take=prev[j];
            dp[j]=max(take,not_take);
        }
        // cout<<"hi"<<endl;
        prev=dp;
    }
    return prev[W];
}