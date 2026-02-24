#include<bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price) {
    // code here
    int n=price.size();
    int totalSum=0;
    vector<int> current(n+1,0);
    for(int i=1;i<=n;i++){
        current[i]=price[0]*i;
    }
    int take,not_take;
    for(int i=1;i<n;i++){
        for(int target=0;target<=n;target++){
            not_take=current[target];
            take=0;
            if(target>i) take=price[i]+current[target-i-1];
            current[target]=max(not_take,take);
        }
    }
    return current[n];
}