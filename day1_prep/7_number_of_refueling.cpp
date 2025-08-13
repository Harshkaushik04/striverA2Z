#include<bits/stdc++.h>
using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    long max_you_can_reach=0;
    int ans=0;
    sort(stations.begin(),stations.end());
    int m=stations.size();
    priority_queue<int,vector<int>> pq;
    pq.push(startFuel);
    int i=0;
    while(max_you_can_reach<target){
        while(i<m && stations[i][0]<=max_you_can_reach){
            pq.push(stations[i][1]);
            i++;
        }
        if(pq.empty()) break;
        max_you_can_reach+=pq.top();
        pq.pop();
        ans++;
    }
    if(max_you_can_reach<target) return -1;
    return ans-1;
}