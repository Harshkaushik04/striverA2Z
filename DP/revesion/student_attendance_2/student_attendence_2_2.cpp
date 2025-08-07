#include<bits/stdc++.h>
using namespace std;

int checkRecord(int n){
    vector<vector<vector<long>>> dp(n,vector<vector<long>>(2,vector<long>(3,0)));
    dp[n-1][0][0]=3;
    dp[n-1][0][1]=3;
    dp[n-1][0][2]=2;
    dp[n-1][1][0]=2;
    dp[n-1][1][1]=2;
    dp[n-1][1][2]=1;
    for(int i=n-2;i>=0;i--){
        for(int j=1;j>=0;j--){
            for(int k=2;k>=0;k--){
                long temp1=0,temp2=0,temp3=0;
                temp1=dp[i+1][j][0];
                if(j==0) temp2=dp[i+1][j+1][0];
                if(k<2) temp3=dp[i+1][j][k+1];
                dp[i][j][k]=(temp1+temp2+temp3)%(1000000007);
            }
        }
    }
    return dp[0][0][0];
}