#include<bits/stdc++.h>
using namespace std;

bool cons(vector<int>& a,vector<int>& b){
    if(a[2]>=b[2]) return false;
    return true;
}

int findUparent(int u,vector<int>& parent){
    if(u==parent[u]) return u;
    parent[u]=findUparent(parent[u],parent);
    return parent[u];
}

void unionBySize(int u,int v,vector<int>& ssize,vector<int>& parent){
    int uPar=findUparent(u,parent);
    int vPar=findUparent(v,parent);
    if(uPar==vPar) return;
    if(ssize[uPar]>ssize[vPar]) parent[uPar]=vPar;
    else if(ssize[uPar]<ssize[vPar]) parent[vPar]=uPar;
    else{
        parent[uPar]=vPar;
        ssize[vPar]+=ssize[uPar];
    }
}

int kruskalsMST(int V, vector<vector<int>> &edges) {
    // code here
    sort(edges.begin(),edges.end(),cons);
    vector<int> parent;
    for(int i=0;i<V;i++) parent.emplace_back(i);
    vector<int> ssize(V,1);
    int n=edges.size();
    int ans=0;
    for(int i=0;i<n;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int uPar=findUparent(u,parent);
        int vPar=findUparent(v,parent);
        if(uPar==vPar) continue;
        if(ssize[uPar]>=ssize[vPar]){
            parent[vPar]=uPar;
            ssize[uPar]+=ssize[vPar];
        }
        else if(ssize[uPar]<ssize[vPar]){
            parent[uPar]=vPar;
            ssize[vPar]+=ssize[uPar];
        }
        ans+=edges[i][2];
    }
    return ans;
}