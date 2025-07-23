#include<bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    int INF=1e9;
    vector<vector<int>> dist(n,vector<int>(n,INF));
    for(int i=0;i<n;i++){
        dist[i][i]=0;
    }
    for(vector<int>& edge:edges){
        dist[edge[0]][edge[1]]=edge[2];
        dist[edge[1]][edge[0]]=edge[2];
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]==INF) continue;
                if(dist[k][j]==INF) continue;
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    int maxi=INT32_MIN;
    int maxi_index=-1;
    for(int i=0;i<n;i++){
        int temp=0;
        for(int j=0;j<n;j++){
            if(dist[i][j]>distanceThreshold) temp++;
        }
        if(maxi<=temp){
            maxi=temp;
            maxi_index=i;
        }
    }
    return maxi_index;
}