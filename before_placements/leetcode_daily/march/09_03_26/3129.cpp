#include<bits/stdc++.h>
using namespace std;

int f(int prev_which,int rem,int limit,vector<vector<vector<vector<int>>>>& dp,int one,int zero,long mod){
    int i=one+zero-1;
    if(one==-1 || zero==-1) return 0;
    if(i==-1) return 1;
    if(dp[rem][prev_which][one][zero]!=-1) return dp[rem][prev_which][one][zero];
    if(rem==0){
        if(prev_which==1) dp[rem][prev_which][one][zero]=f(0,limit-1,limit,dp,one,zero-1,mod);
        else dp[rem][prev_which][one][zero] = f(1,limit-1,limit,dp,one-1,zero,mod);
    }
    else{
        if(prev_which==1) dp[rem][prev_which][one][zero]=((long)f(0,limit-1,limit,dp,one,zero-1,mod)+(long)f(1,rem-1,limit,dp,one-1,zero,mod))%mod;
        else dp[rem][prev_which][one][zero]=((long)f(1,limit-1,limit,dp,one-1,zero,mod)+(long)f(0,rem-1,limit,dp,one,zero-1,mod))%mod;
    }
    return dp[rem][prev_which][one][zero];
}

int numberOfStableArrays(int zero, int one, int limit) {
    vector<vector<vector<vector<int>>>> dp(limit+1,vector<vector<vector<int>>>(2,vector<vector<int>>(one+1,vector<int>(zero+1,-1))));
    long mod=1e9+7;
    int ans=((long)f(0,limit-1,limit,dp,one,zero-1,mod)+(long)f(1,limit-1,limit,dp,one-1,zero,mod))%mod;
    return ans;
}


void printVec(vector<int>& curr){
    int n=curr.size();
    cout<<"{";
    for(int i=0;i<n;i++){
        if(i!=n-1) cout<<curr[i]<<",";
        else cout<<curr[i];
    }
    cout<<"}"<<endl;
}

int f1(int prev_which,int rem,int limit,vector<vector<vector<vector<int>>>>& dp,int one,int zero,vector<int>& curr){
    int i=one+zero-1;
    if(one==-1 || zero==-1) return 0;
    if(i==-1){
        printVec(curr);
        return 1;
    }
    if(dp[rem][prev_which][one][zero]!=-1) {
        cout<<"till now:";
        printVec(curr);
        return dp[rem][prev_which][one][zero];
    }
    if(rem==0){
        if(prev_which==1){
            curr.emplace_back(0);
            dp[rem][prev_which][one][zero]=f1(0,limit-1,limit,dp,one,zero-1,curr);
            curr.pop_back();
        }
        else{
            curr.emplace_back(1);
            dp[rem][prev_which][one][zero] = f1(1,limit-1,limit,dp,one-1,zero,curr);
            curr.pop_back();
        }
    }
    else{
        if(prev_which==1){
            curr.emplace_back(0);
            dp[rem][prev_which][one][zero]=f1(0,limit-1,limit,dp,one,zero-1,curr);
            curr.pop_back();
            curr.emplace_back(1);
            dp[rem][prev_which][one][zero]+=f1(1,rem-1,limit,dp,one-1,zero,curr);
            curr.pop_back();
        }
        else{
            curr.emplace_back(1);
            dp[rem][prev_which][one][zero]=f1(1,limit-1,limit,dp,one-1,zero,curr);
            curr.pop_back();
            curr.emplace_back(0);
            dp[rem][prev_which][one][zero]+=f1(0,rem-1,limit,dp,one,zero-1,curr);
            curr.pop_back();
        }
    }
    return dp[rem][prev_which][one][zero];
}

int numberOfStableArrays1(int zero, int one, int limit) {
    int n=zero+one;
    vector<vector<vector<vector<int>>>> dp(limit,vector<vector<vector<int>>>(2,vector<vector<int>>(one+1,vector<int>(zero+1,-1))));
    vector<int> curr={1};
    int ans=f1(1,limit-1,limit,dp,one-1,zero,curr);
    curr.pop_back();
    curr.emplace_back(0);
    ans+=f1(0,limit-1,limit,dp,one,zero-1,curr);
    curr.pop_back();
    return ans;
}

int main(){
    int zero,one,limit;
    cin>>zero>>one>>limit;
    cout<<numberOfStableArrays1(zero,one,limit)<<endl;
    return 0;
}