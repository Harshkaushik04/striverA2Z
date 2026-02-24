#include<bits/stdc++.h>
using namespace std;

bool isCycle(int V,vector<int> adj[]){
    vector<int> visited_arr(V,0);
    bool ans=false;
    for(int i=0;i<V;i++){
        if(visited_arr[i]==0){
            traversal(i,-1,&adj,&visited_arr,&ans);
        }
        if(ans) break;
    }
    return ans;
}

void traversal(int start,int parent,vector<int>** adjP,vector<int>* visited_arrP,bool* ansP){
    if(*ansP) return;
    int adjSize=(*adjP)[start].size();
    for(int j=0;j<adjSize;j++){
        if((*visited_arrP)[(*adjP)[start][j]]==1 && (*adjP)[start][j]!=parent){
            *ansP=true;
            break;
        }
        else if((*visited_arrP)[(*adjP)[start][j]]==0){
            (*visited_arrP)[(*adjP)[start][j]]=1;
            traversal((*adjP)[start][j],start,adjP,visited_arrP,ansP);
        }
    }
}

int main(){
    return 0;
}