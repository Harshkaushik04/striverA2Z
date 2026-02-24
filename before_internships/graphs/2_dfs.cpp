#include<bits/stdc++.h>
using namespace std;

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> visited_array(V,0);
    vector<int> ans;
    for(int i=0;i<V;i++){
        if(visited_array[i]==0){
            traversal(i,V,&adj,&visited_array,&ans);
        }
    }
    return ans;
}

void traversal(int start,int V,vector<int>** adj,vector<int>* visited_array,vector<int>* ans){
    if((*visited_array)[start]==0){
        (*ans).emplace_back(start);
        (*visited_array)[start]=1;
        int adjSize=(*adj)[start].size();
        for(int i=0;i<adjSize;i++){
            traversal((*adj)[start][i],V,adj,visited_array,ans);
        }
    }
}

