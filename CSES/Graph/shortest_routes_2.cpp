#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m,q;
    const long long INF=1e14;
    cin>>n>>m>>q;
    vector<vector<long long>> dist(n+1,vector<long long>(n+1,INF));
    for(long long i=1;i<=n;i++){
        dist[i][i]=0;
    }
    long long temp1,temp2,temp3;
    for(int i=0;i<m;i++){
        cin>>temp1>>temp2>>temp3;
        dist[temp1][temp2]=min(dist[temp1][temp2],temp3);
        dist[temp2][temp1]=min(dist[temp2][temp1],temp3);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    int q1,q2;
    for(int i=0;i<q;i++){
        cin>>q1>>q2;
        if(dist[q1][q2]!=INF) cout<<dist[q1][q2]<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}