#include<bits/stdc++.h>
using namespace std;
int aggressiveCows(vector<int> &stalls, int k) {
    // code here
    int n=stalls.size();
    int mini=INT32_MAX;
    int maxi=INT32_MIN;
    for(int i=0;i<n;i++){
        mini=min(mini,stalls[i]);
        maxi=max(maxi,stalls[i]);
    }
    sort(stalls.begin(),stalls.end());
    int l=0;
    int h=maxi-mini;
    int mid=(l+h)/2;
    int ans=-1;
    while(l<=h){
        int j=1;
        int prev=stalls[0];
        for(int i=1;i<n;i++){
            if(stalls[i]-prev>=mid){
                j++;
                prev=stalls[i];
            }
        }
        if(j>=k){
            ans=max(ans,mid);
            l=mid+1;
            mid=(l+h)/2;
        }
        else{
            h=mid-1;
            mid=(l+h)/2;
        }
    }
    return ans;
}