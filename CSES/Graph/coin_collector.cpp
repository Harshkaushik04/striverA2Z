#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n,m;
    ll temp1,temp2;
    cin>>n>>m;
    vector<vector<ll>> adj(n,vector<ll>());
    vector<ll> cost(n,0);
    for(int i=0;i<n;i++) cin>>cost[i];
    for(int i=0;i<m;i++){
        cin>>temp1>>temp2;
        adj[temp1].emplace_back(temp2);
    }
    
    return 0;
}