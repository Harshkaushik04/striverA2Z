#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f(int node,int parent_val,int n,int k,vector<int> parents,vector<vector<ll>> dp){
    if(node==1) return 6;
    if(dp[node][parent_val]!=1) return dp[node][parent_val];
    if(parent_val==1) dp[node][parent_val]=f(parents[node],2,n,k,parents,dp);
    else if(parent_val>=2 && parent_val<=5) dp[node][parent_val]=f(parents[node],parent_val-1,n,k,parents,dp)+f(parents[node],parent_val+1,n,k,parents,dp);
    else if(parent_val==6) dp[node][parent_val]=f(parents[node],5,n,k,parents,dp);
    return dp[node][parent_val];
}

int gambler_friendly(int n,int k){
    vector<int> parents(n,-1);
}