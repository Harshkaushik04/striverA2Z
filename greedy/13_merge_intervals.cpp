#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    int n=intervals.size();
    vector<vector<int>> ans=vector<vector<int>>{intervals[0]};
    int index=0;
    int prev_h=intervals[0][1];
    for(int i=1;i<n;i++){
        if(prev_h<intervals[i][0]){
            prev_h=intervals[i][1];
            ans.emplace_back(intervals[i]);
            index++;
        }
        else{
            prev_h=max(prev_h,intervals[i][1]);
            ans[index][1]=prev_h;
        }
    }
    return ans;
}