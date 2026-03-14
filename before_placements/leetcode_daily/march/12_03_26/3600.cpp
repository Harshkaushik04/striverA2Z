#include<bits/stdc++.h>
using namespace std;

int findUpar(int u,vector<int>& parent){
    if(u==parent[u]) return u;
    parent[u]=findUpar(parent[u],parent);
    return parent[u];
}

bool isConnectedGraph(int n,vector<int>& parent){
    int expectedPar=findUpar(0,parent);
    for(int i=1;i<n;i++){
        int par=findUpar(i,parent);
        if(par!=expectedPar) return false;
    }
    return true;
}

static bool cons(vector<int>& a,vector<int>& b){
    if(a[2]>b[2]) return true;
    return false;
}

int maxStability(int n, vector<vector<int>>& edges, int k) {
    vector<int> parent;
    for(int i=0;i<n;i++){
        parent.emplace_back(i);
    }
    vector<int> ssize(n,1);
    vector<int> must;
    vector<int> selected;
    sort(edges.begin(),edges.end(),cons);
    for(vector<int>& edge:edges){
        if(edge[3]==1){
            int uPar=findUpar(edge[0],parent);
            int vPar=findUpar(edge[1],parent);
            if(uPar==vPar) return -1;
            if(ssize[uPar]>=ssize[vPar]){
                parent[vPar]=uPar;
                ssize[uPar]+=ssize[vPar];
            }
            else{
                parent[uPar]=vPar;
                ssize[vPar]+=ssize[uPar];
            }
            must.emplace_back(edge[2]);
        }   
    }
    for(vector<int>& edge:edges){
        if(edge[3]==0){
            int uPar=findUpar(edge[0],parent);
            int vPar=findUpar(edge[1],parent);
            if(uPar==vPar) continue;
            if(ssize[uPar]>=ssize[vPar]){
                parent[vPar]=uPar;
                ssize[uPar]+=ssize[vPar];
            }
            else{
                parent[uPar]=vPar;
                ssize[vPar]+=ssize[uPar];
            }
            selected.emplace_back(edge[2]);
        }
    }
    if(!isConnectedGraph(n,parent)) return -1;
    int len=selected.size();
    int j=0;
    for(int i=len-1;i>=0;i--){
        if(k==0) break;
        selected[i]*=2;
        j++;
        if(j==k) break;
    }
    int len2=must.size();
    for(int i=0;i<len2;i++) selected.emplace_back(must[i]);
    sort(selected.begin(),selected.end());
    return selected[0];
}

int main(){
    vector<vector<int>> edges={{1,3,85282,1},{2,7,15170,1},{5,8,83816,0},{0,9,6574,1},{0,6,97906,0},{7,9,3,0},{8,9,87261,1},{3,9,21740,0},{2,6,90270,0},{3,6,47414,1},{6,9,57119,0},{7,8,46995,0}};
    int n=10;
    int k=7;
    int ans=maxStability(n,edges,k);
    cout<<"ans:"<<ans<<endl;
    return 0;
}