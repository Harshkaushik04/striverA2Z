#include<bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    vector<int> current=triangle[0];
    int n=triangle.size();
    vector<int> next(n,INT32_MAX);
    if(n==1) return triangle[0][0];
    for(int i=0;i<n-1;i++){
        for(int j=0;j<=i;j++){
            if(next[j]!=INT32_MAX) next[j]=min(current[j]+triangle[i+1][j],next[j]);
            else next[j]=current[j]+triangle[i+1][j];
            if(next[j+1]!=INT32_MAX) next[j+1]=min(current[j]+triangle[i+1][j+1],next[j+1]);
            else next[j+1]=current[j]+triangle[i+1][j+1];
        }
        current=next;
        for(int j=0;j<i+2;j++) next[j]=INT32_MAX;
    }
    return *min_element(current.begin(),current.end());
}