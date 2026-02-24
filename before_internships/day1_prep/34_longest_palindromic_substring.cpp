#include<bits/stdc++.h>
using namespace std;
bool f(int i,int j,vector<vector<int>>& dp,string& s,int& maxi
    ,int& i1,int& i2){
        if(i==j){
            dp[i][j]=true;
            if(maxi<1){
                maxi=1;
                i2=j;
                i1=i;
            } 
            return dp[i][j];
        }
        if(i+1==j){
            if(s[i]==s[j]){
                dp[i][j]=true;
                if(maxi<j-i+1){
                    maxi=j-i+1;
                    i2=j;
                    i1=i;
                }
                return dp[i][j];
            }
            else{
                dp[i][j]=false;
                return dp[i][j];
            }
        }
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=(s[i]==s[j]) && f(i+1,j-1,dp,s,maxi,i1,i2);
        if(dp[i][j]){
            if(j-i+1>maxi){
                maxi=j-i+1;
                i1=i;
                i2=j;
            }
        }
        return dp[i][j];
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int i1=-1,i2=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                f(i,j,dp,s,maxi,i1,i2);
            }
        }
        return s.substr(i1,i2-i1+1);
    }