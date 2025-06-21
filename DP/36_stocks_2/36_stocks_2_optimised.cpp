#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<int> current={0,0};
    int temp1,temp2;
    for(int i=n-1;i>=0;i--){
        temp1=max(current[1]+prices[i],current[0]);
        temp2=max(current[0]-prices[i],current[1]);
        current[0]=temp1;
        current[1]=temp2;
    }
    return current[1];
}