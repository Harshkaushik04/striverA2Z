#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(ll i,vector<ll>& visited_arr,stack<ll>& st,vector<vector<ll>>& adj){
    if(visited_arr[i]==-1){
        visited_arr[i]=1;
        for(ll neighbor:adj[i]) dfs(neighbor,visited_arr,st,adj);
        st.push(i);
    }
}

void modifiedDfs(ll i,vector<ll>& visited_arr,vector<vector<ll>>& adj,vector<ll>& ans,ll color){
    if(visited_arr[i]==-1){
        visited_arr[i]=1;
        ans[i]=color;
        for(ll neighbor:adj[i]) modifiedDfs(neighbor,visited_arr,adj,ans,color);
    }
}

void printArr1(vector<vector<ll>> arr,string message){
    ll ssize1=arr.size();
    cout<<"========================="<<endl;
    cout<<message<<":"<<endl;
    for(ll i=0;i<ssize1;i++){
        for(ll j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    } 
    cout<<"========================="<<endl;
}

void printArr2(vector<ll> arr,string message){
    ll ssize=arr.size();
    cout<<"========================="<<endl;
    cout<<message<<":"<<endl;
    for(ll i=0;i<ssize;i++) cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"========================="<<endl;
}

int main(){
    ll n,m;
    ll temp1,temp2;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1,vector<ll>());
    vector<ll> cost(n+1,0);
    for(ll i=1;i<=n;i++) cin>>cost[i];
    for(ll i=0;i<m;i++){
        cin>>temp1>>temp2;
        adj[temp1].emplace_back(temp2);
    }
    // printArr1(adj,"adj");
    //kosaraju algo
    stack<ll> st;
    vector<ll> visited_arr(n+1,-1);
    for(ll i=1;i<=n;i++){
        if(visited_arr[i]==-1) dfs(i,visited_arr,st,adj);
    }
    vector<vector<ll>> adj1(n+1,vector<ll>());
    for(ll i=0;i<=n;i++){
        for(ll num:adj[i]) adj1[num].emplace_back(i);
    }
    // printArr1(adj1,"adj1");
    for(ll i=0;i<=n;i++) visited_arr[i]=-1;
    vector<ll> group(n+1,0);
    ll num_groups=0;
    while(!st.empty()){
        ll curr=st.top();
        st.pop();
        if(visited_arr[curr]==-1) modifiedDfs(curr,visited_arr,adj1,group,num_groups);
        else continue;
        num_groups++;
    }
    // printArr2(group,"group");
    vector<ll> scc_cost(num_groups,0);
    vector<vector<ll>> adj2(num_groups,vector<ll>());
    for(ll i=1;i<=n;i++){
        ll num_group=group[i];
        scc_cost[num_group]+=cost[i];
    }
    // printArr2(scc_cost,"scc_cost");
    for(ll i=1;i<=n;i++){
        for(ll j:adj[i]){
            if(group[i]!=group[j]) adj2[group[i]].emplace_back(group[j]);
        }
    }
    // printArr1(adj2,"adj2");
    //topo sort using kahn algo
    n=num_groups;
    vector<ll> indegree(n,0);
    for(ll i=0;i<n;i++){
        for(ll j:adj2[i]){
            indegree[j]++;
        }
    }
    queue<ll> q;
    for(ll i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }
    vector<ll> topo;
    while(!q.empty()){
        ll qSize=q.size();
        for(ll i=0;i<qSize;i++){
            ll current=q.front();
            topo.emplace_back(current);
            q.pop();
            for(ll neighbor:adj2[current]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0) q.push(neighbor);
            }
        }
    }
    // printArr2(topo,"topo");
    vector<ll> dp=scc_cost;
    ll maxi=*max_element(dp.begin(), dp.end());
    for(ll i=0;i<n;i++){
        ll current=topo[i];
        for(ll neighbor:adj2[current]){
            dp[neighbor]=max(dp[neighbor],dp[current]+scc_cost[neighbor]);
            maxi=max(maxi,dp[neighbor]);
        }
    }
    // printArr2(dp,"dp");
    cout<<maxi<<endl;
    return 0;
}