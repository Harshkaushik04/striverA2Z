#include<bits/stdc++.h>
using namespace std;

bool isCycle(int V,vector<int> adj[]){
    vector<int> visited_arr(V,0);
    bool ans=false;
    for(int i=0;i<V;i++){
        if(visited_arr[i]==0){
            traversal(i,&adj,&visited_arr,&ans);
        }
        if(ans==true) break;
    }
    return ans;
}

void traversal(int start,vector<int>** adjP,vector<int>* visited_arrP,bool* ansP){
    queue<pair<int,int>> q;
    pair<int,int> current;
    q.push(make_pair(start,-1));
    (*visited_arrP)[start]=1;
    bool flag=false;
    while(!q.empty()){
        int qSize=q.size();
        for(int i=0;i<qSize;i++){
            current=q.front();
            q.pop();
            int adjSize=(*adjP)[current.first].size();
            for(int j=0;j<adjSize;j++){
                if((*visited_arrP)[(*adjP)[current.first][j]]==1 && (*adjP)[current.first][j]!=current.second){
                    *ansP=true;
                    flag=true;
                    break;
                }
                else if((*visited_arrP)[(*adjP)[current.first][j]]==0){
                    (*visited_arrP)[(*adjP)[current.first][j]]=1;
                    q.push(make_pair((*adjP)[current.first][j],current.first));
                }
            }
            if(flag) break;
        }
        if(flag) break;
    }
}

int main(){
    return 0;
}