#include<bits/stdc++.h>
using namespace std;

long long power(long long a,long long b,int MOD) {
    long long res = 1;
    a%=MOD;
    while(b>0) {
        if(b%2==1) {
            res=(res*a)%MOD;
        }
        a=(a*a)%MOD;
        b/=2;
    }
    return res;
}

int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    int num_queries=queries.size();
    int n=nums.size();
    vector<int> diff_arr(n,1);
    long long temp=1;
    int MOD=1e9+7;
    unordered_map<int,vector<vector<int>>> mpp;
    for(int i=0;i<num_queries;i++){
        int l=queries[i][0];
        int r=queries[i][1];
        int k=queries[i][2];
        int v=queries[i][3];
        mpp[k].emplace_back(queries[i]);
    }
    for(pair<const int,vector<vector<int>>>& p:mpp){
        int k=p.first;
        int queries_size=p.second.size();
        for(int i=0;i<queries_size;i++){
            int l=p.second[i][0];
            int r=p.second[i][1];
            int k=p.second[i][2];
            int v=p.second[i][3];
            temp=diff_arr[l];
            temp*=(long long)v;
            temp%=MOD;
            diff_arr[l]=temp;
            int num_steps=(r-l)/k;
            int next=l+(num_steps+1)*k;
            if(next<n){
                temp=(long long)diff_arr[next]*power(v,MOD-2,MOD);
                temp%=MOD;
                diff_arr[next]=temp;
            }
        }
        for(int i=0;i<n;i++){
            if(i-k>=0){
                temp=diff_arr[i];
                temp*=(long long) diff_arr[i-k];
                temp%=MOD;
                diff_arr[i]=temp;
            }
        }
    }  
    for(int i=0;i<n;i++){
        temp=nums[i];
        temp*=(long long)diff_arr[i];
        temp%=MOD;
        nums[i]=temp;
    }     
    temp=nums[0];
    for(int i=1;i<n;i++){
        temp^=nums[i];
    } 
    return temp;
}

int main(){
    return 0;
}