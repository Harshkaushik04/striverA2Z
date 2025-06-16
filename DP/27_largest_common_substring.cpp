#include<bits/stdc++.h>
using namespace std;


//memoiazation solution in tradiitonal way not possible because its not subsequence
//if forces to memoize it would use double for loop then function which is not optimal
//following solution is not correct since it doesnt go completely from top to down, it stops in between
//and doesnt go till bottom

// int f(int index1,int index2,vector<vector<int>>& dp,string s1,string s2,int& maxi){
//     if((index1==0)||(index2==0)){
//         if(s1[index1]==s2[index2]){
//             dp[index1][index2]=1;
//             return 1;
//         }
//         else{
//             dp[index1][index2]=0;
//             return 0;
//         }
//     }
//     if(dp[index1][index2]!=-1) return dp[index1][index2];
//     if(s1[index1]==s2[index2]){
//         dp[index1][index2]=1+f(index1-1,index2-1,dp,s1,s2,maxi);
//         if(dp[index1][index2]>maxi) maxi=dp[index1][index2];
//     }
//     else{
//         dp[index1][index2]=0;
//     }
//     return dp[index1][index2];
// }

// int longestCommonSubstr(string& s1, string& s2) {
//     // your code here
//     int size1=s1.size();
//     int size2=s2.size();
//     vector<vector<int>> dp(size1,vector<int>(size2,0));
//     int maxi=0;
//     int random=f(size1-1,size2-1,dp,s1,s2,maxi);
//     return maxi;
// }

int longestCommonSubstr(string& s1,string& s2){
    //your code here
    int size1=s1.size();
    int size2=s2.size();
    vector<vector<int>> dp(size1,vector<int>(size2,0));
    int ans=0;
    for(int i=0;i<size1;i++){
        if(s1[i]==s2[0]) {
            dp[i][0]=1;
            ans=1;
        }

    }
    for(int i=0;i<size2;i++){
        if(s1[0]==s2[i]) {
            dp[0][i]=1;
            ans=1;
        }
    }
    for(int i=1;i<size1;i++){
        for(int j=1;j<size2;j++){
            if(s1[i]==s2[j]) {
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>ans) ans=dp[i][j];
            }
        }
    }
    return ans;
}

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int maxi=longestCommonSubstr(s1,s2);
    cout<<maxi<<endl;
    return 0;
}