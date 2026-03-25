#include<bits/stdc++.h>
using namespace std;

    bool canPartitionGrid(vector<vector<int>>& grid) {
    long total_sum=0;
    int n=grid.size();
    int m=grid[0].size();
    vector<long> sums(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            total_sum+=(long)grid[i][j];
        }
        sums[i]=total_sum;
    }        
    for(int i=0;i<n;i++){
        if(2*sums[i]==total_sum) return true;
    }
    total_sum=0;
    sums.resize(m);
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            total_sum+=(long)grid[i][j];
        }
        sums[j]=total_sum;
    }      
    for(int i=0;i<m;i++){
        if(2*sums[i]==total_sum) return true;
    }
    return false;
}
int main(){
    return 0;
}