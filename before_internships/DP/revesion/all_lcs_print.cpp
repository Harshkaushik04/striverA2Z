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


void do_procedure(string& s1,string& s2,int i,int j,vector<vector<int>>& dp,set<string>& vec,string& ans){ //string not passed by reference
    if(dp[i][j]==0){
        vec.insert(ans);
        return;
    }
    if(i==0){
        ans+=s1[i];
        vec.insert(ans);
        ans.pop_back();
        return;
    }
    if(j==0){
        ans+=s2[j];
        vec.insert(ans);
        ans.pop_back();
        return;
    } 
    if(i>0 && j>0){
        if(s1[i]==s2[j]) {
            ans+=s1[i];
            do_procedure(s1,s2,i-1,j-1,dp,vec,ans);
            ans.pop_back();
        }
        else{
            if(dp[i][j-1]==dp[i][j]) do_procedure(s1,s2,i,j-1,dp,vec,ans);
            if(dp[i-1][j]==dp[i][j]) do_procedure(s1,s2,i-1,j,dp,vec,ans);
        }
    }
}

vector<string> allLCS(string &s1, string &s2) {
    // Code here
    set<string> vec;
    vector<vector<int>> dp=make_lcs_table(s1,s2);
    int m=s1.size();
    int n=s2.size();
    string ans;
    do_procedure(s1,s2,m-1,n-1,dp,vec,ans);
    vector<string> actual_ans(vec.begin(),vec.end());
    for(string& s:actual_ans) reverse(s.begin(),s.end());
    return actual_ans;
}

void printArr(vector<string>& vec){
    for(string& s:vec) cout<<s<<" ";
    cout<<endl;
}
int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    vector<string> vec=allLCS(s1,s2);
    printArr(vec);
    return 0;
}