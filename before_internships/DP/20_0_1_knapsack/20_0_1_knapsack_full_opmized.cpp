#include<bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    // code here
    int n=val.size();
    vector<int> current(W+1,0);
    if(W>=wt[0]) {
        for(int i=wt[0];i<=W;i++)
        current[i]=val[0];
    }
    int take,not_take;
    for(int i=1;i<n;i++){
        for(int target=W;target>=0;target--){
            not_take=current[target];
            take=0;
            if(target>=wt[i]) take=val[i]+current[target-wt[i]];
            current[target]=max(take,not_take);
        }
    }
    return current[W];
}