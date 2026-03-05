#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int,string>& a,const pair<int,string>& b){
    if(a.first>b.first) return false;
    else if(a.first<b.first) return true;
    else{
        if(a.second=="start1" || a.second=="start2") return true;
        else return false; 
    }
}

vector<pair<int,string>> lineSweep_events(vector<vector<int>>& l1,vector<vector<int>>& l2){
    vector<pair<int,string>> ans;
    for(vector<int>& R:l1){
        ans.emplace_back(pair<int,string>{R[0],"start1"});
        ans.emplace_back(pair<int,string>{R[1],"end1"});
    }
    for(vector<int>& R:l2){
        ans.emplace_back(pair<int,string>{R[0],"start2"});
        ans.emplace_back(pair<int,string>{R[1],"end2"});
    }
    sort(ans.begin(),ans.end(),comp);
    return ans;
}

vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
    vector<pair<int,string>> lse = lineSweep_events(firstList,secondList);
    int n=lse.size();
    int temp=0;
    int i=0,start=-1;
    vector<vector<int>> ans;
    while(i<n){
        if(lse[i].second=="start1" || lse[i].second=="start2"){
            if(temp==1){
                start=lse[i].first;
                temp++;
            }
            else temp++;
        }
        else{
            if(temp==2){
                ans.emplace_back(vector<int>{start,lse[i].first});
                start=-1;
                temp--;
            }
            else temp--;
        }
        i++;
    }
    return ans;
}

int main(){
    return 0;
}