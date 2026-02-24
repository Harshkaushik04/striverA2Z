#include<bits/stdc++.h>
using namespace std;

int graph_cities(int A,vector<vector<int>>& B,vector<int>& C,int D,int E){
    int n=A;
    vector<vector<int>> edges=B;
    int m=edges.size();
    unordered_map<int,int> loud;
    int num_loud=C.size();
    for(int i=0;i<num_loud;i++) loud[C[i]]=1;
    int source=D;
    int dest=E;
    vector<vector<int>> adj(n+1,vector<int>());
    for(vector<int>& edge:edges){
        adj[edge[0]].emplace_back(edge[1]);
        adj[edge[1]].emplace_back(edge[0]);
    }
    int l=0,h=m;
    int mid=(l+h)/2;
    int ans=INT32_MAX;
    while(l<=h){
        bool flag=true;
        queue<vector<int>> q;
        vector<int> vis(n+1,-1);
        q.push(vector<int>{source,-1,0}); //node,parent,dist
        vis[source]=1;
        while(!q.empty()){
            int qSize=q.size();
            if(!flag) break;
            for(int i=0;i<qSize;i++){
                vector<int> current=q.front();
                q.pop();
                if(current[2]>mid){
                    flag=false;
                    break;
                }
                if(current[0]==dest) continue;
                for(int neighbor:adj[current[0]]){
                    if(neighbor!=current[1]){
                        if(loud.find(neighbor)!=loud.end()) q.push(vector<int>{neighbor,current[0],0});
                        else q.push(vector<int>{neighbor,current[0],current[2]+1});
                    }
                }
            }
            if(!flag) break;
        }
        if(flag){
            ans=min(ans,mid);
            h=mid-1;
            mid=(l+h)/2;
        }
        else{
            l=mid+1;
            mid=(l+h)/2;
        }
    }
    return ans;
}

int main(){
    int A,D,E;
    vector<vector<int>> B;
    vector<int> C;
    int m,loud_m;
    cin>>A;
    cin>>m;
    int temp1,temp2;
    for(int i=0;i<m;i++){
        cin>>temp1>>temp2;
        B.emplace_back(vector<int>{temp1,temp2});
    }
    cin>>loud_m;
    for(int i=0;i<loud_m;i++){
        cin>>temp1;
        C.emplace_back(temp1);
    }
    cin>>D>>E;
    int ans=graph_cities(A,B,C,D,E);
    cout<<ans<<endl;
    return 0;
}