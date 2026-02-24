#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
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
    queue<int> q;
    q.push(start);
    (*visited_array)[start]=1;
    int qSize;
    int current,tempSize;
    while(!q.empty()){
        qSize=q.size();
        for(int i=0;i<qSize;i++){
            current=q.front();
            q.pop();
            (*ans).emplace_back(current);
            tempSize=(*adj)[current].size();
            for(int j=0;j<tempSize;j++){
                if((*visited_array)[(*adj)[current][j]]==0) {
                    q.push((*adj)[current][j]);
                    (*visited_array)[(*adj)[current][j]]=1;
                }
            }
        }
    }
}