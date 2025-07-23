#include<bits/stdc++.h>
using namespace std;

void actualDfs(int i,int root,vector<int> adj[],vector<int>& visited_arr,int& num){
    if(visited_arr[i]==-1){
        visited_arr[i]=1;
        for(int neighbor:adj[i]) {
            if(i==root && visited_arr[neighbor]==-1) num++;
            if(num>1) return;
            actualDfs(neighbor,root,adj,visited_arr,num);
        }
    }
}

bool is_single_child(int i,vector<int> adj[],int n){
    vector<int> visited_arr(n,-1);
    bool ans=true;
    int num=0;
    actualDfs(i,i,adj,visited_arr,num);
    if(num>1) return false;
    return true;
}

void Maindfs(int i,int parent,vector<int> adj[],vector<int>& visited_arr,vector<int>& disc_arr,vector<int>& best_arr,int& time,set<int>& ans,int n){
    if(visited_arr[i]==-1){
        visited_arr[i]=1;
        disc_arr[i]=time;
        best_arr[i]=time;
        time++;
        for(int neighbor:adj[i]){
            bool flag=false;
            if(visited_arr[neighbor]==1 && neighbor!=parent) {
                best_arr[i]=min(best_arr[i],disc_arr[neighbor]);
                flag=true;
            }
            Maindfs(neighbor,i,adj,visited_arr,disc_arr,best_arr,time,ans,n);
            if(best_arr[neighbor]!=-1 && neighbor!=parent && !flag){
                best_arr[i]=min(best_arr[i],best_arr[neighbor]);
            }
        }
        if(parent>0 && best_arr[i]>=disc_arr[parent]) ans.insert(parent);
        if(parent==-1 && !is_single_child(i,adj,n)) ans.insert(i);
    }
}

vector<int> articulationPoints(int n, vector<int> adj[]){
    vector<int> visited_arr(n,-1);
    vector<int> disc_arr(n,-1);
    vector<int> best_arr(n,-1);
    int time=1;
    set<int> ans;
    for(int i=0;i<n;i++){
        if(visited_arr[i]==-1){
            Maindfs(i,-1,adj,visited_arr,disc_arr,best_arr,time,ans,n);
        }
    }
    if(ans.size()==0) return vector<int>{-1};
    vector<int> actual_ans(ans.begin(),ans.end());
    return actual_ans;
}