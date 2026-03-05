#include<bits/stdc++.h>
using namespace std;
int minOperations(string s, int k) {
    int n=s.size();
    int m=0; //num_zeros
    //num_ones=n-m
    for(int i=0;i<n;i++){
        if(s[i]=='0') m++;
    }        
    if(m==0) return 0;
    if(m%2==1 && k%2==0){
        return -1;
    }
    if(k==n && m>0 && n-m>0) return -1;
    if(max(0,k+m-n)>min(m,k)) return -1;
    queue<int> q;
    unordered_map<int,int> visited_arr;
    visited_arr[m]=1;
    q.push(m);
    int ans=0;
    while(!q.empty()){
        int qSize=q.size();
        ans++;
        for(int j=0;j<qSize;j++){
            int curr_m=q.front();
            q.pop();
            int up_lim=max(0,curr_m+k-n);
            int down_lim=min(curr_m,k);
            for(int i=up_lim;i<=down_lim;i++){
                int state=curr_m+k-2*i;
                if(visited_arr.find(state)==visited_arr.end()){
                    q.push(state);
                    visited_arr[state]=1;
                    if(state==0) return ans;
                }
            }
        }
    }
    return ans;
}