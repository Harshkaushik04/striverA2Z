#include<bits/stdc++.h>
using namespace std;

int numProvinces(int V, vector<int> adj[]) {
    vector<int> visited_array(V,0);
    int actual_ans=0;
    for(int i=0;i<V;i++){
        if(visited_array[i]==0){
            traversal(i,V,&adj,&visited_array);
            actual_ans++;
        }
    }
    return actual_ans;
}

void traversal(int start,int V,vector<int>** adj,vector<int>* visited_array){
    if((*visited_array)[start]==0){
        (*visited_array)[start]=1;
        int adjSize=(*adj)[start].size();
        for(int i=0;i<adjSize;i++){
            traversal((*adj)[start][i],V,adj,visited_array);
        }
    }
}