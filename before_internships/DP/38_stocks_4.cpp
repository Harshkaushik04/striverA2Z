#include<bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> current(2,vector<int>(k+1,0));
    vector<vector<int>> temp=current;
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<k;j++){
            temp[1][j]=max(current[1][j],current[0][j+1]-prices[i]);
            temp[0][j]=max(current[0][j],current[1][j]+prices[i]);
        }
        temp[1][0]=max(current[1][0],current[0][1]-prices[i]);
        temp[0][k]=max(current[0][k],current[1][k]+prices[i]);
        current=temp;
    }
    return current[1][0];
}