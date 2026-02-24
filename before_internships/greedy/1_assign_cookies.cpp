#include<bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int gSize=g.size();
    int sSize=s.size();
    int temp1,temp2;
    int j=0,ans=0;
    for(int i=0;i<sSize;i++){
        temp1=s[sSize-i-1];
        temp2=INT32_MAX;
        while(temp2>temp1){
            temp2=g[gSize-j-1];
            if(temp2<=temp1){
                ans++;
                j++;
                break;
            }
            j++;
            if(j>gSize-1) return ans;
        }
        if(j>gSize-1) return ans;
    }
    return ans;
}