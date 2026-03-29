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
    bool change=true;
    char to_be_introduced='b';
    for(int i=1;i<n;i++){
        if(lcp[0][i]==0){
            if(to_be_introduced=='b') to_be_introduced='c';
            s[i]='b';
        }
        else s[i]='a';
    }        
    if(to_be_introduced=='b') change=false;
    bool introduced=false;
    for(int i=1;i<n;i++){
        introduced=false;
        for(int j=i+1;j<n;j++){
            if(!change){
                if(lcp[i][j]==0){
                    if(s[i]==s[j]) return "";
                    else continue;
                }
                else{
                    if(s[i]==s[j]) continue;
                    else return "";
                }
            }
            else{
                if(!introduced){
                    if(lcp[i][j]==0){
                        if(s[i]==s[j]){
                            if(s[i]==(char)to_be_introduced-1){
                                introduced=true;
                                s[j]=to_be_introduced;
                                to_be_introduced++;
                            }
                            else return "";
                        }
                        else continue;   
                    }
                    else{
                        if(s[i]==s[j]) continue;
                        else return "";
                    }
                }
                else{
                    if(lcp[i][j]==0){
                        if(s[i]==s[j]){
                            if(s[i]==(char) to_be_introduced-2) s[i]=(char) to_be_introduced-1;
                            else return "";
                        }
                        else continue;
                    }
                    else{
                        if(s[i]==s[j]) continue;
                        else return "";
                    }
                }
            }
        }
        if(to_be_introduced!='a'+i+3) change=false;
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