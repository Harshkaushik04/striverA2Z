#include<bits/stdc++.h>
using namespace std;

void printArr(vector<vector<int>>& arr){
    int arrSize=arr.size();
    int arrSize1=arr[0].size();
    for(int i=0;i<arrSize;i++){
        for(int j=0;j<arrSize1;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


int maximumPoints(vector<vector<int>>& arr){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(4,-1));
    vector<int> nums={0,1,2};
    int maxi=-1;
    for(int i:nums){
        for(int j:nums){
            if(i!=j){
                maxi=max(maxi,arr[0][j]);
            }
        }
        dp[0][i]=maxi;
        maxi=-1;
    }
    dp[0][3]=max(arr[0][0],arr[0][1]);
    dp[0][3]=max(dp[0][3],arr[0][2]);
    vector<int> temp(3,-1);
    for(int i=1;i<n;i++){
        for(int j:nums){
            for(int k:nums){
                if(j!=k){
                    temp[k]=arr[i][k]+dp[i-1][k];    
                }
            }
            maxi=temp[0];
            if(maxi<temp[1]) maxi=temp[1];
            if(maxi<temp[2]) maxi=temp[2];
            temp[0]=-1,temp[1]=-1,temp[2]=-1;
            dp[i][j]=maxi;
        }
    }
    maxi=dp[n-1][0];
    if(maxi<dp[n-1][1]){
        maxi=dp[n-1][1];
    }
    if(maxi<dp[n-1][2]){
        maxi=dp[n-1][2];
    }
    return maxi;
} 

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(3,-1));
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }
    int ans=maximumPoints(arr);
    cout<<"ans:"<<ans<<endl;
    return 0;
}