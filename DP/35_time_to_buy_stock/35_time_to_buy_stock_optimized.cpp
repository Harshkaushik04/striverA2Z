#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int mini,ans=0;
    mini=prices[0];
    for(int i=0;i<n;i++){
        if(mini>prices[i]) mini=prices[i];
        if(ans<prices[i]-mini) ans=prices[i]-mini;
    }
    return ans;
}