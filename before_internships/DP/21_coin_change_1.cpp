#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n=coins.size();
    vector<int> current(amount+1,amount+1);
    int m=amount/coins[0];
    for(int i=0;i<=m;i++){
        current[i*coins[0]]=i;
    }
    int take,not_take;
    for(int i=1;i<n;i++){
        for(int target=0;target<=amount;target++){
            not_take=current[target];
            take=amount+1;
            if(target>=coins[i] && current[target-coins[i]]!=amount+1) take=1+current[target-coins[i]]; //allows to take as many coins as needed
            current[target]=min(take,not_take);
        }
    }
    if(current[amount]==amount+1) return -1;
    return current[amount];
}