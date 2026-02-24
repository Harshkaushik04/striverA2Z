#include<bits/stdc++.h>
using namespace std;

long long solve(vector<int>& bt) {
    // code here
    int n=bt.size();
    sort(bt.begin(),bt.end());
    long long sum=0,avg=0;
    for(int i=0;i<n;i++){
        avg+=sum;
        sum+=bt[i];
    }
    return avg/n;
}