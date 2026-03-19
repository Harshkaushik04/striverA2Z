#include<bits/stdc++.h>
using namespace std;

void printVec(vector<vector<int>>& vec){
    int n=vec.size();
    int m=vec[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}

int numberOfSubmatrices(vector<vector<char>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> whetherXPresent(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0){
                if(grid[i][j]=='X') whetherXPresent[i][j]=1;
            } 
            else if((i==0)){
                if(grid[i][j]=='X' || whetherXPresent[i][j-1]==1) whetherXPresent[i][j]=1;
            } 
            else if((j==0)){
                if(grid[i][j]=='X' || whetherXPresent[i-1][j]==1) whetherXPresent[i][j]=1;
            } 
            else{
                if(grid[i][j]=='X' || whetherXPresent[i][j-1]==1 || whetherXPresent[i-1][j]==1) whetherXPresent[i][j]=1;
            }
        }
    }
    vector<vector<int>> dp(n,vector<int>(m,0));
    int ans=0;
    int counter=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='X') counter=1;
            else if(grid[i][j]=='Y') counter=-1;
            else counter=0;
            if(i==0 && j==0) dp[i][j]=counter;
            else if(i==0){
                dp[i][j]=dp[i][j-1]+counter;
                if(whetherXPresent[i][j] && dp[i][j]==0) ans++;
            } 
            else if(j==0){
                dp[i][j]=dp[i-1][j]+counter;
                if(whetherXPresent[i][j] && dp[i][j]==0) ans++;
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+counter;
                if(whetherXPresent[i][j] && dp[i][j]==0) ans++;
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<char>> grid={{'.','X'},{'.','Y'}};
    int ans=numberOfSubmatrices(grid);
    cout<<"ans:"<<ans<<endl;
    return 0;
}