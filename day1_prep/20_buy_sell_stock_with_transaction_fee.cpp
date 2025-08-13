#include<bits/stdc++.h>
using namespace std;

//tabulation
int maxProfit(vector<int>& prices,int fee) {
    int n=prices.size();
    int curr1=0,curr2=-prices[0]-fee;
    int temp1,temp2;
    for(int i=1;i<n;i++){
        temp1=max(prices[i]+curr2,curr1);
        temp2=max(-prices[i]+curr1-fee,curr2);
        curr1=temp1;
        curr2=temp2;
    }
    return curr1;
}