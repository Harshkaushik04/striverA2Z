#include<bits/stdc++.h>
using namespace std;

vector<int> col_peak(vector<vector<int>>& mat,int col,int m,int n){
    int maxi=mat[0][col];
    int maxi_index=0;
    for(int i=0;i<m;i++){
        if(mat[i][col]>maxi){
            maxi=mat[i][col];
            maxi_index=i;
        }
    }
    return vector<int>{maxi_index,col};
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();
    int l=0,h=n-1;
    int mid=(l+h)/2;
    while(l<=h){
        vector<int> max_pair=col_peak(mat,mid,m,n);
        if(n==1) return max_pair;
        int i=max_pair[0];
        int j=max_pair[1];
        if(j==0){
            if(mat[i][j]>mat[i][j+1]) return max_pair;
            else{
                l=mid+1;
                mid=(l+h)/2;
            }
        }
        else if(j==n-1){
            if(mat[i][j]>mat[i][j-1]) return max_pair;
            else{
                h=mid-1;
                mid=(l+h)/2;
            }
        }
        else{
            if(mat[i][j]>mat[i][j+1] && mat[i][j]>mat[i][j-1]) return max_pair;
            else if(mat[i][j]<=mat[i][j+1]){
                l=mid+1;
                mid=(l+h)/2;
            }
            else if(mat[i][j]<=mat[i][j-1]){
                h=mid-1;
                mid=(l+h)/2;
            }
        }
    }
    return vector<int>{-1};
}