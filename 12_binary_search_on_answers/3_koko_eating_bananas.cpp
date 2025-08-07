#include<bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int n=piles.size();
    int l=1,high=-1;
    for(int i=0;i<n;i++) high=max(high,piles[i]);
    int mid=(l+high)/2;
    int ans=-1;
    while(l<=high){
        int hours=0;
        for(int i=0;i<n;i++){
            if(piles[i]%mid==0) hours+=(piles[i]/mid);
            else hours+=(piles[i]/mid+1);
        }
        if(hours==h){
            ans=mid;
            high=mid-1;
            mid=(l+high)/2;
        }
        else if(hours>h){
            l=mid+1;
            mid=(l+high)/2;
        }
        else{
            high=mid-1;
            mid=(l+high)/2;
        }
    }
    return ans;
}

int main(){
    int n,h;
    cin>>n>>h;
    vector<int> piles(n,-1);
    for(int i=0;i<n;i++) cin>>piles[i];
    cout<<minEatingSpeed(piles,h)<<endl;
    return 0;
}