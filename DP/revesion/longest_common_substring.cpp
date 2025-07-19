#include<bits/stdc++.h>
using namespace std;

/*
f(i,j,s1,s2,m,n,dp){ -> length of common substring from 0....i and 0...j backward starting from i and j 
    if(i==0){
        for(int k=0;k<=j;k++){
        if(s1[i]==s2[k]) return 1;
        }
        return 0;
    } 
    if(j==0){
        for(int k=0;k<=i;k++){
        if(s1[i]==s2[k]) return 1;
    }
    return 0;
    }  
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
        dp[i][j]=1+f(i-1,j-1,s1,s2,m,n,dp);
    }
    else d[i][j]=0;
    return dp[i][j];
}
*/
