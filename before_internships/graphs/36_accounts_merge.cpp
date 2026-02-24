#include<bits/stdc++.h>
using namespace std;

int findUp(vector<int>& parent,vector<int>& size_arr,int u){
    if(u==parent[u]) return u;
    int up=findUp(parent,size_arr,parent[u]);
    parent[u]=up;
    return up;
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<int,string> mpp;
    int n=accounts.size();
    for(int i=0;i<n;i++){
        mpp[i]=accounts[i][0];
    }
    vector<int> parents;
    for(int i=0;i<n;i++){
        parents.emplace_back(i);
    }
    vector<int> size_arr(n,1);
    unordered_map<string,int> mapping;
    for(int i=0;i<n;i++){
        int tempSize=accounts[i].size();
        for(int j=1;j<tempSize;j++){
            unordered_map<string,int>::iterator temp=mapping.find(accounts[i][j]);
            if(temp!=mapping.end()){
                int up1=findUp(parents,size_arr,mapping[accounts[i][j]]);
                int up2=findUp(parents,size_arr,i);
                if(up1==up2) continue;
                if(size_arr[up1]>=size_arr[up2]){
                    parents[up2]=up1;
                    size_arr[up1]+=size_arr[up2];
                }
                else if(size_arr[up1]<size_arr[up2]){
                    parents[up1]=up2;
                    size_arr[up2]+=size_arr[up1];
                }
            }
            else mapping[accounts[i][j]]=i;
        }
    }
    vector<vector<string>> ans;
    unordered_map<int,int> another_mpp;
    int j=0;
    for(pair<string,int> p:mapping){
        int temp2=findUp(parents,size_arr,p.second);
        unordered_map<int,int>::iterator temp=another_mpp.find(temp2);
        if(temp!=another_mpp.end()){
            ans[another_mpp[temp2]].emplace_back(p.first);
        }
        else{
            another_mpp[temp2]=j;
            j++;
            ans.emplace_back(vector<string>{mpp[temp2]});
            ans[another_mpp[temp2]].emplace_back(p.first);
        }
    }
    int tempSize=ans.size();
    for(int i=0;i<tempSize;i++){
        sort(ans[i].begin()+1,ans[i].end());
    }
    return ans;
}