#include<bits/stdc++.h>
using namespace std;

void dfs(int i,vector<int>& visited_arr,stack<int>& st,vector<vector<int>>& adj){
    if(visited_arr[i]==-1){
        visited_arr[i]=1;
        for(int neighbor:adj[i]) dfs(neighbor,visited_arr,st,adj);
        st.push(i);
    }
}

void modifiedDfs(int i,vector<int>& visited_arr,vector<vector<int>>& adj,vector<int>& ans,int color){
    if(visited_arr[i]==-1){
        visited_arr[i]=1;
        ans[i]=color;
        for(int neighbor:adj[i]) modifiedDfs(neighbor,visited_arr,adj,ans,color);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int temp1,temp2;
    vector<vector<int>> adj(n+1,vector<int>());
    for(int i=0;i<m;i++){
        cin>>temp1>>temp2;
        adj[temp1].emplace_back(temp2);
    }
    stack<int> st;
    vector<int> visited_arr(n+1,-1);
    for(int i=1;i<=n;i++){
        if(visited_arr[i]==-1) dfs(i,visited_arr,st,adj);
    }
    vector<vector<int>> adj1(n+1,vector<int>());
    for(int i=0;i<=n;i++){
        for(int num:adj[i]) adj1[num].emplace_back(i);
    }
    for(int i=0;i<=n;i++) visited_arr[i]=-1;
    vector<int> ans(n+1,0);
    int ans1=1;
    while(!st.empty()){
        int curr=st.top();
        st.pop();
        if(visited_arr[curr]==-1) modifiedDfs(curr,visited_arr,adj1,ans,ans1);
        else continue;
        ans1++;
    }
    cout<<ans1-1<<endl;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}