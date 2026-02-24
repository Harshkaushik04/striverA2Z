#include<bits/stdc++.h>
using namespace std;
//not done
// vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//     int startingIndex=-1,endingIndex=-1; //initialise
//     int n=intervals.size();
//     int i=0;
//     vector<vector<int>> ans;
//     while(i<n && intervals[i][0]<newInterval[0]){
//         ans.emplace_back(intervals[i]);
//         i++;
//     }
//     if(i==n){
//         if(intervals[n-1][1]>newInterval[0]){
//             if(interval[n-1][1]<newInterval[1]) ans[n-1][1]=newInterval[1]; 
//         }
//         else ans.emplace_back(newInterval);
//     }
//     else{
//         int index=0;
//         if(intervals[i-1][1]>newInterval[0]){
//             if(interval[n-1][1]<newInterval[1]){

//             }
//         }
//     }
// }