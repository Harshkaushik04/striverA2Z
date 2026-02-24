#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
    vector<int> rank;
    vector<int> size;
    vector<int> parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<n+1;i++){
            parent.emplace_back(i);
        }
    }
    int findUpar(int u){
        if(u==parent[u]) return u;
        int uPar=findUpar(parent[u]);
        parent[u]=uPar;
        return uPar;
    }
    void unionByRank(int u,int v){
        int up_u=findUpar(u);
        int up_v=findUpar(v);
        if(up_u==up_v) return;
        if(rank[up_u]>rank[up_v]) parent[up_v]=up_u;
        else if(rank[up_u]<rank[up_v]) parent[up_u]=up_v;
        else{
            parent[up_v]=up_u;
            rank[up_u]++;
        }
    }
    void unionBySize(int u,int v){
        int up_u=findUpar(u);
        int up_v=findUpar(v);
        if(up_u==up_v) return;
        if(size[up_u]>=size[up_v]){
            parent[up_v]=up_u;
            size[up_v]+=size[up_u];
        }
        else if(size[up_u]<size[up_v]){
            parent[up_u]=up_v;
            size[up_u]+=size[up_v];
        }
    }
};