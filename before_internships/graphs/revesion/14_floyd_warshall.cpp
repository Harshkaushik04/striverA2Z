#include<bits/stdc++.h>
using namespace std;
//doesnt contain negative cycle
void floydWarshall(vector<vector<int>> &dist) {
    // Code here
    int N=dist.size();
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if (dist[i][k] != 1e8 && dist[k][j] != 1e8) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}