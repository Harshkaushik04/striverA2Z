#include<bits/stdc++.h>
using namespace std;

int shipWithinDays(vector<int>& weights, int days) {
    int n=weights.size();
    int total=0;
    int l=weights[0];
    for(int i=0;i<n;i++){
        l=max(l,weights[i]);
        total+=weights[i];
    }
    int h=total;
    int mid=(l+h)/2;
    int ans=INT32_MAX;
    while(l<=h){
        int j=1;
        int counter=0;
        for(int i=0;i<n;i++){
            if(counter+weights[i]<=mid) counter+=weights[i];
            else{
                counter=weights[i];
                j++;
            }
        }
        if(j>days){
            l=mid+1;
            mid=(l+h)/2;
        }
        else{
            ans=min(ans,mid);
            h=mid-1;
            mid=(l+h)/2;
        }
    }   
    return ans;  
}