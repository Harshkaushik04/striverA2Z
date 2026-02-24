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

int f(vector<vector<int>>& arr,int index,int last,vector<vector<int>>& dp){
    //last:
    //0------->task1
    //1------->task2
    //2------->task3
    //3------->no task
    int maxi=-1;
    if(index==0){
        for(int i=0;i<3;i++){
            if(i!=last){
                if(arr[0][i]>maxi) maxi=arr[0][i];
            }
        }
        return maxi;
    }
    vector<int> temp(3,0);
    for(int i=0;i<3;i++){
        if(i!=last){
            if(dp[index-1][i]==-1){ 
                temp[i]=arr[index][i]+f(arr,index-1,i,dp);
            }
            else {
                temp[i]=arr[index][i]+dp[index-1][i];
            }
        }
    }
    //max logic
    if(last==0){
        if(temp[2]>=temp[1]) dp[index][last]=temp[2];
        else dp[index][last]=temp[1];
    }
    else if(last==1){
        if(temp[0]>=temp[2]) dp[index][last]=temp[0];
        else dp[index][last]=temp[2]; 
    }
    else if(last==2){
        if(temp[0]>=temp[1]) dp[index][last]=temp[0];
        else dp[index][last]=temp[1];
    }
    else{ //last==3
        if(temp[2]>=temp[1]) {
            if(temp[0]>=temp[2]) dp[index][last]=temp[0];
            else dp[index][last]=temp[2];
        }
        else{
            if(temp[0]>=temp[1]) dp[index][last]=temp[0];
            else dp[index][last]=temp[1];
        }
    }
    return dp[index][last];
}

int maximumPoints(vector<vector<int>>& arr) {
    // Code here
    //[running,fighting,learning]
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(4,-1));
    int ans=f(arr,n-1,3,dp);
    // printArr(dp);
    return ans;
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