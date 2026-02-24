#include<bits/stdc++.h>
using namespace std;

int change(int amount,vector<int>& coins) {
    sort(coins.begin(),coins.end());
    int n=coins.size();
    vector<long> current(amount+1,0);
    int m=amount/coins[0];
    long take,not_take;
    for(int i=0;i<=m;i++){
        current[i*coins[0]]=1;
    }
    for(int i=1;i<n;i++){
        for(int target=coins[i];target<=amount;target++){
            take=current[target];
            not_take=current[target-coins[i]];
            current[target]=take+not_take;
        }
    }
    return current[amount];
}