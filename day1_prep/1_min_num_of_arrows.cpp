#include<bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    int n=points.size();
    if(n==0) return 0;
    if(n==1) return 1;
    sort(points.begin(),points.end());
    vector<int> current_interval=points[0];
    int ans=1;
    for(int i=1;i<n;i++){
        if(points[i][0]<=current_interval[1]){
            current_interval[0]=points[i][0];
            current_interval[1]=min(points[i][1],current_interval[1]);
        }
        else{
            current_interval=points[i];
            ans++;
        }
    }
    return ans;
}