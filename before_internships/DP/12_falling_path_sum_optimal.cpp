#include<bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<int> current=matrix[0];
    vector<int> next(n,INT32_MAX);
    if(n==1) return *min_element(current.begin(),current.end());
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            if(next[j]!=INT32_MAX) next[j]=min(current[j]+matrix[i+1][j],next[j]);
            else next[j]=current[j]+matrix[i+1][j];
            if(j+1<n){
                if(next[j+1]!=INT32_MAX) next[j+1]=min(current[j]+matrix[i+1][j+1],next[j+1]);
                else next[j+1]=current[j]+matrix[i+1][j+1];
            }
            if(j-1>=0){
                if(next[j-1]!=INT32_MAX) next[j-1]=min(current[j]+matrix[i+1][j-1],next[j-1]);
                else next[j-1]=current[j]+matrix[i+1][j-1];
            }
        }
        current=next;
        for(int j=0;j<n;j++) next[j]=INT32_MAX;
    }
    return *min_element(current.begin(),current.end());
}