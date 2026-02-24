#include<bits/stdc++.h>
using namespace std;


int f(vector<int>& val,vector<int>& wt,vector<vector<int>>& dp,int index,int target){
    if(target==0) {
        dp[index][target]=0;
        return 0;
    }
    if(index==0){
        if(target>=wt[0]) {
            dp[index][target]=val[0];
            return val[0];
        }
        else {
            dp[index][target]=0;
            return 0;
        }
    }
    if(dp[index][target]!=-1) return dp[index][target];
    int not_take,take;
    not_take=f(val,wt,dp,index-1,target);
    take=0;
    if(target>=wt[index]) take=val[index]+f(val,wt,dp,index-1,target-wt[index]);
    dp[index][target]=max(take,not_take);
    return dp[index][target];
}

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    // code here
    int n=val.size();
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return f(val,wt,dp,n-1,W);
}


int main(){
    vector<int> val,wt;
    int n,W,temp;
    cin>>n>>W;
    for(int i=0;i<n;i++){
        cin>>temp;
        val.emplace_back(temp);
    }
    for(int i=0;i<n;i++){
        cin>>temp;
        wt.emplace_back(temp);
    }
    cout<<knapsack(W,val,wt)<<endl;
    return 0;
}
