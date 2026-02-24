#include<bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &mat) {
    // code here
    int m=mat.size();
    int n=mat[0].size();
    int mini=INT32_MAX,maxi=INT32_MIN;
    for(int i=0;i<m;i++){
        mini=min(mini,mat[i][0]);
        maxi=max(maxi,mat[i][n-1]);
    }
    int l=mini,h=maxi;
    int mid=(l+h)/2;
    int desired=(m*n)/2;
    while(l<h){
        mid=(l+h)/2;
        int count=0;
        for(int i=0;i<m;i++){
            count+=(upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin());
        }
        if(count<=desired) l=mid+1; 
        else h=mid-1;
    }
    return l;
}