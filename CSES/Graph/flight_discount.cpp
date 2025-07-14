#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    const ll INF=1e15;
    ll n,m;
    cin>>n>>m;
    ll temp1,temp2,temp3;
    vector<vector<pair<ll,ll>>> adj(n+1,vector<pair<ll,ll>>());
    for(int i=0;i<m;i++){
        cin>>temp1>>temp2>>temp3;
        adj[temp1].emplace_back(make_pair(temp2,temp3));
    }
    priority_queue<tuple<ll,ll,bool>,vector<tuple<ll,ll,bool>>,greater<>> pq; //distance,node,whether_discount
    tuple<ll,ll,bool> p1={0,1,false};
    pair<ll,ll> p=make_pair(INF,INF);
    vector<pair<ll,ll>> distance_arr(n+1,p); //distance without discount,distance with discount
    distance_arr[1]=make_pair(0,0);
    pq.push(p1);
    while(!pq.empty()){
        tuple<ll,ll,bool> current=pq.top(); //distance,node,whether_discount
        ll current_distance=get<0>(current);
        ll current_node=get<1>(current);
        bool whether_discount=get<2>(current);
        pq.pop();
        if((current_distance>distance_arr[current_node].second && whether_discount)||
        (current_distance>distance_arr[current_node].first && !whether_discount)) continue;
        for(pair<ll,ll> neighbor:adj[current_node]){ //neighbor={neighbor node,edge weight}
            //no discount
            if(distance_arr[neighbor.first].first>distance_arr[current_node].first+neighbor.second){
                distance_arr[neighbor.first].first=distance_arr[current_node].first+neighbor.second;
                pq.push(tuple<ll,ll,bool>{distance_arr[neighbor.first].first,neighbor.first,false});
            }
            //discount
            if(distance_arr[neighbor.first].second>distance_arr[current_node].first+neighbor.second/2){
                distance_arr[neighbor.first].second=distance_arr[current_node].first+neighbor.second/2;
                pq.push(tuple<ll,ll,bool>{distance_arr[neighbor.first].second,neighbor.first,true});
            }
            if(distance_arr[neighbor.first].second>distance_arr[current_node].second+neighbor.second){
                distance_arr[neighbor.first].second=distance_arr[current_node].second+neighbor.second;
                pq.push(tuple<ll,ll,bool>{distance_arr[neighbor.first].second,neighbor.first,true});
            }
        }
    }
    cout<<distance_arr[n].second<<endl;
    return 0;
}