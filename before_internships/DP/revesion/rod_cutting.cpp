#include<bits/stdc++.h>
using namespace std;

int cutRod(vector<int> &price) {
    // code here
    int len=price.size();
    vector<int> dp(len+1,0);
    for(int index=len-1;index>=0;index--){
        for(int length=0;length<=len;length++){
            int take=0,not_take=0;
            if(length-index-1>=0) take=dp[length-index-1]+price[index];
            not_take=dp[length];
            dp[length]=max(take,not_take);
        }
    }
    return dp[len];
}