#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> find_arr(int unit_nodes,vector<int>& units_from,vector<int>& units_to,vector<int>& units_weights,int x){
    int n=unit_nodes;
    int m=units_from.size();
    vector<int> ans(n,-1);
    ans[0]=x;
    ll temp=1,MOD=1000000007;
    vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>());
    for(int i=0;i<m;i++){
        adj[units_from[i]].emplace_back(make_pair(units_to[i],units_weights[i]));
    }
    queue<vector<int>> q; //node,parent,node weight
    q.push(vector<int>{1,-1,ans[0]});
    vector<int> visited_arr(n+1,-1); 
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            vector<int> current=q.front();
            if(current[1]!=-1) temp=(ll)ans[current[1]-1]*(ll)current[2];
            else temp=ans[0];
            temp%=MOD;
            ans[current[0]-1]=temp;
            q.pop();
            for(pair<int,int> neighbor:adj[current[0]]){
                if(visited_arr[neighbor.first]==-1){
                    visited_arr[neighbor.first]=1;
                    q.push(vector<int>{neighbor.first,current[0],neighbor.second});
                }
            }
        }
    }
    return ans;
}

int main(){
    int unit_nodes,x,temp;
    cin>>unit_nodes>>x;
    vector<int> units_from(unit_nodes-1,-1),units_to(unit_nodes-1,-1),units_weights(unit_nodes-1,-1);
    for(int i=0;i<unit_nodes-1;i++){
        cin>>units_from[i]>>units_to[i]>>units_weights[i];
    }
    vector<int> ans=find_arr(unit_nodes,units_from,units_to,units_weights,x);
    for(int i=0;i<unit_nodes;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}