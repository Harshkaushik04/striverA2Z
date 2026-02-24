#include<bits/stdc++.h>
using namespace std;

long f(int i,int absent,int cons,int whether_late,vector<vector<vector<vector<long>>>>& dp){
    if(cons<0||absent<0) return 0;
    if(whether_late && cons==0) return 0;
    if(!whether_late && cons>0) return 0;
    if(i==0){
        if((absent==1||absent==0)&&(!whether_late)&&(cons==0)||(cons==1 && whether_late && absent==0)||(cons==0 && !whether_late)) return 1;
        else return 0;
    }
    if(dp[i][absent][cons][whether_late]!=-1) return dp[i][absent][cons][whether_late];
    if(whether_late){
        int temp1,temp2;
        temp1=f(i-1,absent,cons-1,true,dp);
        temp2=f(i-1,absent,cons-1,false,dp);
        dp[i][absent][cons][whether_late]=(temp1+temp2)%(1000000007);
    }
    else{
        dp[i][absent][cons][whether_late]=(f(i-1,absent-1,0,false,dp)+f(i-1,absent-1,1,true,dp)+f(i-1,absent-1,2,true,dp)
        +f(i-1,absent,0,false,dp)+f(i-1,absent,1,true,dp)+f(i-1,absent,2,true,dp))%(1000000007);
    }
    return dp[i][absent][cons][whether_late];
}

int checkRecord(int n) {
    long ans=0;
    vector<vector<vector<vector<long>>>> dp(n,vector<vector<vector<long>>>(2,vector<vector<long>>(3,vector<long>(2,-1))));
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<2;k++){
                ans=(ans+f(n-1,i,j,k,dp))%(1000000007);
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<checkRecord(n)<<endl;
    return 0;
}