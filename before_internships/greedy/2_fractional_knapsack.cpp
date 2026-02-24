#include<bits/stdc++.h>
using namespace std;

double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    // code here
    int n=val.size();
    vector<pair<double,int>> vec;
    double ratio;
    double ans=0;
    for(int i=0;i<n;i++){
        ratio=(double) val[i]/wt[i];
        vec.emplace_back(make_pair(ratio,i));
    }
    sort(vec.rbegin(),vec.rend());
    for(int i=0;i<n;i++){
        if(wt[vec[i].second]<=capacity){
            capacity-=wt[vec[i].second];
            ans+=val[vec[i].second];
        }
        else{
            ans+=capacity*vec[i].first;
            capacity=0;
            break;
        }
    }
    return ans;
}

int main(){
    int n,m;
    vector<int> val,wt;
    int capacity;
    int temp;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>temp;
        val.emplace_back(temp);
    }
    for(int i=0;i<m;i++){
        cin>>temp;
        wt.emplace_back(temp);
    }
    cin>>capacity;
    cout<<fractionalKnapsack(val,wt,capacity)<<endl;
    return 0;
}