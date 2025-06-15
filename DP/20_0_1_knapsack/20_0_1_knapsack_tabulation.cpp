#include<bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt) {
    // code here
    int n=val.size();
    vector<int> current(W+1,0);
    vector<int> last(W+1,0);
    if(W>=wt[0]) {
        for(int i=wt[0];i<=W;i++)
        last[i]=val[0];
    }
    int take,not_take;
    for(int i=1;i<n;i++){
        for(int target=0;target<=W;target++){
            not_take=last[target];
            take=0;
            if(target>=wt[i]) take=val[i]+last[target-wt[i]];
            current[target]=max(take,not_take);
        }
        last=current;
    }
    return last[W];
}
int main(){
    vector<int> val,wt;
    int n,W,temp;
    cin>>n>>W;
    for(int i=0;i<n;i++){
        cin>>temp;
        val.emplace_back(temp);
    }
    for(int i=0;i<n;i++){
        cin>>temp;
        wt.emplace_back(temp);
    }
    cout<<knapsack(W,val,wt)<<endl;
    return 0;
}

