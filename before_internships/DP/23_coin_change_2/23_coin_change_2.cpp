#include<bits/stdc++.h>
using namespace std;

int change(int amount,vector<int>& coins) {
    int n=coins.size();
    vector<int> current(amount+1,0);
    int m=amount/coins[0];
    for(int i=0;i<=m;i++){
        current[i*coins[0]]=1;
    }
    int take,not_take;
    for(int i=1;i<n;i++){
        for(int target=0;target<=amount;target++){
            not_take=current[target];
            take=0;
            if(target>=coins[i]) take=current[target-coins[i]]; //allows to take as many coins as needed
            current[target]=take+not_take;
        }
    }
    return current[amount];
}