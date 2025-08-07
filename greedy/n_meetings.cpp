#include<bits/stdc++.h>
using namespace std;

int maxMeetings(vector<int>& start, vector<int>& end) {
    // Your code here
    vector<pair<int,int>> vec;
    int n=start.size();
    for(int i=0;i<n;i++){
        vec.emplace_back(make_pair(start[i],end[i]));
    }
    sort(vec.begin(),vec.end());
    int l=-1,h=-1; //initialise
    int ans=0;
    for(int i=0;i<n;i++){
        if(vec[i].first>h) ans++;
        else if(vec[i].first<=h && vec[i].second>h) continue;
        l=vec[i].first;
        h=vec[i].second;
    }
    return ans;
}