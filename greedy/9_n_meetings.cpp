#include<bits/stdc++.h>
using namespace std;

vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
    vector<pair<pair<int,int>,int>> vec;
    for(int i=0;i<N;i++){
        vec.emplace_back(make_pair(make_pair(F[i],S[i]),i));
    }
    sort(vec.begin(),vec.end());
    int freeTime=-1; //initialise
    vector<int> ans;
    for(int i=0;i<N;i++){
        if(vec[i].first.second>freeTime){
            freeTime=vec[i].first.first;
            ans.emplace_back(vec[i].second+1);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}