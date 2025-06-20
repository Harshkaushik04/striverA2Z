#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>& vec1,vector<int>& vec2){
    return vec1[1]<vec2[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),cmp);
    int freeTime=-1; //initialise
    int n=intervals.size();
    int num_erase=0;
    for(int i=0;i<n;i++){
        if(intervals[i][0]>=freeTime){
            freeTime=intervals[i][1];
        }
        else num_erase++;
    }
    return num_erase;
}

int main(){
    return 0;
}