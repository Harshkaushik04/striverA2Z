#include<bits/stdc++.h>
using namespace std;
// struct comp{
//     bool operator()(pair<long long,long long> a,pair<long long,long long> b){
//         if(a.second>b.second) return true;
//         return false;
//     }
// };



int main(){
    long long n,m;
    cin>>n>>m;
    vector<vector<pair<long long,long long>>> adj(n+1,vector<pair<long long,long long>>());
    long long temp1,temp2,temp3;
    for(long long i=0;i<m;i++){
        cin>>temp1>>temp2>>temp3;
        adj[temp1].emplace_back(make_pair(temp2,temp3));
    }
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
    pq.push(make_pair(0,1));
    vector<long long> distance_arr(n+1,LONG_LONG_MAX);
    distance_arr[1]=0;
    while(!pq.empty()){
        pair<long long,long long> p=pq.top();
        pq.pop();
        if(distance_arr[p.second]<p.first) continue;
        for(pair<long long,long long> neighbor:adj[p.second]){
            if(distance_arr[neighbor.first]>p.first+neighbor.second){
                distance_arr[neighbor.first]=p.first+neighbor.second;
                pq.push(make_pair(distance_arr[neighbor.first],neighbor.first));
            }
        }
    }
    for(long long i=1;i<=n;i++) cout<<distance_arr[i]<<" ";
    cout<<endl;
    return 0;
}