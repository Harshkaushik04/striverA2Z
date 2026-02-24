#include<bits/stdc++.h>
using namespace std;
//can be solved using disjoint set, getting tle with this greedy approach
vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    // code here
    int n=deadline.size();
    vector<int> ansArr(n,-1);
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        vec.emplace_back(make_pair(profit[i],deadline[i]));
    }
    sort(vec.begin(),vec.end(),greater<pair<int,int>>());
    int index=0; //initialise
    int numJobs=0,totalProfit=0;
    for(int i=0;i<n;i++){
        index=vec[i].second-1;
        while(ansArr[index]!=-1 && index>=0) index--;
        if(index<0) continue;
        ansArr[index]=vec[i].first;
        totalProfit+=ansArr[index];
        numJobs++;
    }
    vector<int> ans={numJobs,totalProfit};
    return ans;
}