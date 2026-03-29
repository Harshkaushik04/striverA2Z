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
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int m=0;m<lcp[i][j];m++){
                dsuUnion(i+m,j+m,parent,size);
            }
            if(i+lcp[i][j]<n && j+lcp[i][j]<n) inequalities.emplace_back(pair<int,int>{i+lcp[i][j],j+lcp[i][j]});
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