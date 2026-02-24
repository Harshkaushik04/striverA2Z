#include<bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    int row=heights.size();
    int col=heights[0].size();
    vector<vector<int>> effort_arr(row,vector<int>(col,INT32_MAX));
    effort_arr[0][0]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; //{effort,{row,col}}
    pq.push(make_pair(0,make_pair(0,0)));
    vector<int> rx={0,1,0,-1};
    vector<int> ry={1,0,-1,0};
    while(!pq.empty()){
        pair<int,pair<int,int>> current=pq.top();
        pq.pop();
        if(current.first>effort_arr[current.second.first][current.second.second]) continue;
        for(int i=0;i<4;i++){
            int x=current.second.first+rx[i];
            int y=current.second.second+ry[i];
            if(x>=0 && x<row && y>=0 && y<col){
                int new_value=abs(heights[x][y]-heights[current.second.first][current.second.second]);
                int compared_value=max(new_value,current.first);
                if(compared_value<effort_arr[x][y]){
                    effort_arr[x][y]=compared_value;
                    pq.push(make_pair(compared_value,make_pair(x,y)));
                }
            }
        }
    }    
    return effort_arr[row-1][col-1];
}