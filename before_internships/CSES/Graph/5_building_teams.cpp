#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> edgesToAdj(vector<vector<int>>& edges,int n){
    vector<vector<int>> adj(n+1,vector<int>());
    for(vector<int> vec:edges){
        adj[vec[0]].emplace_back(vec[1]);
        adj[vec[1]].emplace_back(vec[0]);
    }
    return adj;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m,vector<int>(2,0));
    for(int i=0;i<m;i++) cin>>edges[i][0]>>edges[i][1];
    vector<vector<int>> adj=edgesToAdj(edges,n);
    vector<int> visited_arr(n+1,-1);
    int current_color,diff_color,temp;
    bool impossible_flag=false;
    for(int i=1;i<n+1;i++){
        if(impossible_flag) break;
        if(visited_arr[i]==-1){
            queue<int> q;
            q.push(i);
            int color1=1,color2=2;
            current_color=color1,diff_color=color2;
            visited_arr[i]=current_color;
            while(!q.empty()){
                if(impossible_flag) break;
                int qSize=q.size();
                for(int i=0;i<qSize;i++){
                    int current=q.front();
                    q.pop();
                    for(int neighbor:adj[current]){
                        if(visited_arr[neighbor]==-1){
                            visited_arr[neighbor]=diff_color;
                            q.push(neighbor);
                        }
                        else if(visited_arr[neighbor]==diff_color) continue;
                        else {
                            impossible_flag=true;
                            break;
                        }
                    }
                }
                temp=diff_color;
                diff_color=current_color;
                current_color=temp;
            }
        }
    }
    if(impossible_flag) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i=1;i<n+1;i++) cout<<visited_arr[i]<<" ";
        cout<<endl;
    }
    return 0;
}