#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> make_lcs_table(string& s1,string& s2){
    int m=s1.size();
    int n=s2.size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    bool flag=false;
    int next_index=-1;
    for(int i=0;i<m;i++){
        if(s1[i]==s2[0]){
            flag=true;
            dp[i][0]=1;
            next_index=i+1;
            break;
        } 
    }
    if(flag && next_index!=-1 && next_index<m){
        for(int i=next_index;i<m;i++){
            dp[i][0]=1;  
        }
    }
    flag=false,next_index=-1;
    for(int i=0;i<n;i++){
        if(s2[i]==s1[0]){
            flag=true;
            dp[0][i]=1;
            next_index=i+1;
            break;
        }
    }
    if(flag && next_index!=-1 && next_index<n){
        for(int i=next_index;i<n;i++){
            dp[0][i]=1;
        }
    }
    for(int j=1;j<n;j++){
        for(int i=1;i<m;i++){
            if(s1[i]==s2[j]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp;
}


string shortestCommonSupersequence(string s1, string s2) {
    vector<vector<int>> dp=make_lcs_table(s1,s2);
    int m=s1.size();
    int n=s2.size();
    int i=m-1,j=n-1;
    string ans;
    while(i>=0 && j>=0 && dp[i][j]!=0){
        // cout<<"hi"<<endl;
        if(i>0 && j>0){
            if(dp[i][j-1]==dp[i][j]) {
                ans+=s2[j];
                j--;
            }
            else if(dp[i-1][j]==dp[i][j]){
                ans+=s1[i];
                i--;
            }
            else if(dp[i-1][j-1]+1==dp[i][j]){
                ans+=s1[i];
                i--;
                j--;
            }
        }
        else if(i==0 && j!=0){
            if(dp[i][j]==dp[i][j-1]){
                ans+=s2[j];
                j--;
            }
            else{
                ans+=s2[j];
                i--;
                j--;
            }
        }
        else if(i!=0 && j==0){
            if(dp[i][j]==dp[i-1][j]){
                ans+=s1[i];
                i--;
            }
            else{
                ans+=s1[i];
                i--;
                j--;
            }
        }
        else{
            ans+=s1[0];
            i--;
            j--;
        }
    }
    int end1=i,end2=j;
    if(end1>=0){
        for(int i=end1;i>=0;i--) ans+=s1[i];
    }
    if(end2>=0){
        for(int j=end2;j>=0;j--) ans+=s2[j];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}