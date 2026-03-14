#include<bits/stdc++.h>
using namespace std;
bool checkIfWorks(int maxWeight,vector<int>& weights,int days,int maxi){
    int n=weights.size();
    if(maxWeight<maxi) return false;
    int elpasedDays=1;
    int temp=0;
    for(int i=n-1;i>=0;i--){
        if(temp+weights[i]<=maxWeight) temp+=weights[i];
        else{
            elpasedDays++;
            if(elpasedDays>days) return false;
            temp=weights[i];
        }
    }
    return true;
}

int shipWithinDays(vector<int>& weights, int days) {
    int n=weights.size();
    int sum=0;
    int maxi=weights[0];
    for(int i=0;i<n;i++){
        sum+=weights[i];
        if(weights[i]>maxi) maxi=weights[i];
    }
    int left=1,right=sum;
    int mid=(left+right)/2;
    int ans=mid;
    while(true){
        bool check=checkIfWorks(mid,weights,days,maxi);
        if(check){
            right=mid-1;
            ans=mid;
        }
        else left=mid+1;
        if(left>right) return ans;
        mid=(left+right)/2;
    }
    return ans;
}