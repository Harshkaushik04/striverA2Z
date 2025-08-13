#include<bits/stdc++.h>
using namespace std;

void printArr(vector<vector<int>>& arr){
    int n=arr.size();
    int m=arr[0].size();
    cout<<"===================="<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"===================="<<endl;
}

int countSquares(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    int ans=0;
    for(int i=0;i<n;i++){
        dp[i][0]=matrix[i][0];
        ans+=dp[i][0];
    }
    for(int i=0;i<m;i++){
        dp[0][i]=matrix[0][i];
        ans+=dp[0][i];
    }
    ans-=dp[0][0];
    int temp;
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]==0) continue;
            temp=min(dp[i-1][j],dp[i][j-1]);
            dp[i][j]=(min(temp,dp[i-1][j-1])+1);
            ans+=dp[i][j];
        }
    }
    // printArr(dp);
    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<countSquares(matrix)<<endl;
    return 0;
}