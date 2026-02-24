#include<bits/stdc++.h>
using namespace std;

// first merge all intervals and find if query is in interval
/*
we can first sort vector<vector<int>> based on start time 
we can keep an ans_intervals vector<vector<int>> and also a vector<int> current_interval 
traverse throught intervals array, let intervals[i]=interval_i
if interval_i[0]>=current_interval[1] =>update current interval to {current_interval[0],interval_i[1]}
else append current_interval to ans_intervals and update current_interval to interval_i
*/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    int n=intervals.size();
    vector<vector<int>> ans_intervals;
    vector<int> current_interval=intervals[0];
    for(int i=1;i<n;i++){
        if(current_interval[1]>=intervals[i][0]) current_interval[1]=max(current_interval[1],intervals[i][1]);
        else{
            ans_intervals.emplace_back(current_interval);
            current_interval=intervals[i];
        }
    }
    ans_intervals.emplace_back(current_interval);
    return ans_intervals;
}

/*
first we would sort intervals, reason for osrting intervals in both merge and insert is that we can
intuitively think about merging intervals greedily 
[][][{][][][}][][]
let interval to be selected be x
phase 1: before starting bracket of interval
compare the ending bracket of each interval with starting backet of x
phase2: between
compare ending bracket of x with starting bracket of each interval and keep increasing current_interval while condition
is true
phase3: after
just keep inserting all remaining intervals into ans
*/

vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int> to_be_inserted){
    int iterating_index=0;
    int ssize=intervals.size();
    vector<vector<int>> ans_intervals;
    while(iterating_index<ssize && intervals[iterating_index][1]<to_be_inserted[0]){
        ans_intervals.emplace_back(intervals[iterating_index]);
        iterating_index++;
    }
    vector<int> current_interval=to_be_inserted;
    while(iterating_index<ssize && intervals[iterating_index][0]<=to_be_inserted[1]){
        current_interval[0]=min(current_interval[0],intervals[iterating_index][0]);
        current_interval[1]=max(current_interval[1],intervals[iterating_index][1]);
        iterating_index++;
    }
    ans_intervals.emplace_back(current_interval);
    while(iterating_index<ssize){
        ans_intervals.emplace_back(intervals[iterating_index]);
        iterating_index++;
    }
    return ans_intervals;
}