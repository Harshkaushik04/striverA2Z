#include<bits/stdc++.h>
using namespace std;

int findPar(int i,vector<int>& parent){
    if(i==parent[i]) return i;
    int grandParent_i=findPar(parent[i],parent);
    parent[i]=grandParent_i;
    return parent[i];
}

void dsuUnion(int i,int j,vector<int>& parent,vector<int>& size){
    int pi=findPar(i,parent);
    int pj=findPar(j,parent);
    if(pi==pj) return;
    else{
        if(size[pi]>=size[pj]){
            parent[pj]=pi;
            size[pi]+=size[pj];
        }
        else{
            parent[pi]=pj;
            size[pj]+=size[pi];
        }
    }
}

string findTheString(vector<vector<int>>& lcp) {
    int n=lcp.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(lcp[i][j]!=lcp[j][i]) return "";
            if(lcp[i][j]>min(n-i,n-j)) return "";
        }
    }
    vector<pair<int,int>> inequalities;
    vector<int> parent(n,-1);
    vector<int> size(n,1);
    for(int i=0;i<n;i++) parent[i]=i;
    for(int j=0;j<n;j++){
        int j1=j;
        int i1=0;
        vector<pair<pair<int,int>,pair<int,int>>> ranges={{{i1,j1},{i1+lcp[i1][j1],j1+lcp[i1][j1]}}};
        while(j1<n){
            pair<pair<int,int>,pair<int,int>> curr_range=ranges[ranges.size()-1];
            if(curr_range.second.first>=i1){
                curr_range.second={max(curr_range.second.first,i1+lcp[i1][j1]),max(curr_range.second.second,j1+lcp[i1][j1])};
                ranges.pop_back();
            }
            else curr_range={{i1,j1},{i1+lcp[i1][j1],j1+lcp[i1][j1]}};
            ranges.emplace_back(curr_range);
            if(i1+lcp[i1][j1]<n && j1+lcp[i1][j1]<n) inequalities.emplace_back(pair<int,int>{i1+lcp[i1][j1],j1+lcp[i1][j1]});
            i1++;
            j1++;
        }
        for(const pair<pair<int,int>,pair<int,int>>& range:ranges){
            int m=range.second.first-range.first.first;
            int i1=range.first.first;
            int j1=range.first.second;
            for(int i=0;i<m;i++){
                dsuUnion(i1+i,j1+i,parent,size);
            }
        }
    }
    for(const pair<int,int>& p:inequalities){
        if(findPar(p.first,parent)==findPar(p.second,parent)) return "";
    }
    unordered_map<int,char> mpp;
    string s="";
    char curr='a'-1;
    for(int i=0;i<n;i++){
        int p=findPar(i,parent);
        if(mpp.find(p)==mpp.end()){
            if(curr=='z') return "";
            curr++;
            mpp[p]=curr;
        }
        s+=mpp[p];
    }
    return s;
}