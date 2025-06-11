#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid)  {
    int m=grid.size(),n=grid[0].size();
    vector<int> next(n,-1);
    vector<int> current(n,-1);
    current[0]=grid[0][0];
    int temp;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j+1<n){
                if(current[j+1]!=-1) {
                    temp=grid[i][j+1]+current[j];
                    current[j+1]=min(current[j+1],temp);
                }
                else current[j+1]=current[j]+grid[i][j+1];
            }
            if(i+1<m) next[j]=current[j];
        }
        if(i!=m-1) current=next;
    }
    return current[n-1];
}
