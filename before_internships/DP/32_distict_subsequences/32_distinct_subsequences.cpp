#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,string& s,string& t,vector<vector<int>>& dp){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) dp[i][j]=f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
    else dp[i][j]=f(i-1,j,s,t,dp);
    return dp[i][j];
}

int numDistinct(string s, string t) {
    int size1=s.size();
    int size2=t.size();
    vector<vector<int>> dp(size1,vector<int>(size2,-1));
    return f(size1-1,size2-1,s,t,dp);
}

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    cout<<numDistinct(s1,s2)<<endl;
    return 0;
}