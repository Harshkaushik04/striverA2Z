#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,string& s,int n,vector<vector<int>>& lcp,set<pair<int,int>>& ss){
    if(i==n-1 || j==n-1){
        if(s[i]==s[j]){
            lcp[i][j]=1;
            ss.erase(pair<int,int>{i,j});
            return lcp[i][j];
        }
        else{
            lcp[i][j]=0;
            ss.erase(pair<int,int>{i,j});
            return lcp[i][j];
        }
    }
    if(lcp[i][j]!=-1) return lcp[i][j];
    if(s[i]==s[j]) lcp[i][j]=1+f(i+1,j+1,s,n,lcp,ss);
    else lcp[i][j]=0;
    ss.erase(pair<int,int>{i,j});
    return lcp[i][j];
}

string findTheString(vector<vector<int>>& lcp) {
    int n=lcp.size();
    string s(n,'a');
    for(int i=1;i<n;i++){
        if(lcp[0][i]==0) s[i]='b';
        else s[i]='a';
    }        
    set<pair<int,int>> ss;
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ss.insert(pair<int,int>{i,j});
        }
    }
    while(!ss.empty()){
        pair<int,int> p=*ss.begin();
        f(p.first,p.second,s,n,dp,ss);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]!=lcp[i][j]) return "";
        }
    }
    return s;
}

void printArr(vector<vector<int>>& arr){
    int n=arr.size();
    int m=arr[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    vector<vector<int>> lcp(n,vector<int>(n,-1));
    set<pair<int,int>> ss;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ss.insert(pair<int,int>{i,j});
        }
    }
    while(!ss.empty()){
        pair<int,int> p=*ss.begin();
        f(p.first,p.second,s,n,lcp,ss);
    }
    printArr(lcp);
    return 0;
}