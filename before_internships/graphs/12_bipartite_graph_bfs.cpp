#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int N=graph.size();
    vector<int> visited_arr(N,-1);
    queue<int> q;
    for(int i=0;i<N;i++){
        if(visited_arr[i]==-1){
            int n=0;
            int currentColor=0,otherColor=1;
            q.push(i);
            visited_arr[i]=currentColor;
            while(!q.empty()){
                int qSize=q.size();
                for(int j=0;j<qSize;j++){
                    if(n%2==0) currentColor=1,otherColor=0;
                    else currentColor=0,otherColor=1;
                    int current=q.front();
                    // cout<<current<<","<<currentColor<<","<<otherColor<<endl;
                    q.pop();
                    vector<int> neighbors=graph[current];
                    for(int neighbor:neighbors){
                        if(visited_arr[neighbor]==otherColor){
                            return false;
                        }
                        else if(visited_arr[neighbor]==currentColor){
                            continue;
                        }
                        else{ // ==-1
                            q.push(neighbor);
                            visited_arr[neighbor]=currentColor;
                        }
                    }
                }
                n++;
            }
        }
    }
    return true;
}

int main(){
    return 0;
}