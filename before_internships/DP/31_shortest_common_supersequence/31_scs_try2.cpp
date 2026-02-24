#include<bits/stdc++.h>
using namespace std;

void printArr(vector<vector<int>> arr){
    int m=arr.size();
    int n=arr[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> makeLcsTable(string& s1,string& s2){
    int m=s1.size();
    int n=s2.size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    int temp=m;
    for(int i=0;i<m;i++){
        if(s1[i]==s2[0]){
            dp[i][0]=1;
            temp=i;
            break;
        }
    }
    for(int i=temp+1;i<m;i++){
        dp[i][0]=1;
    }
    temp=n;
    for(int i=0;i<n;i++){
        if(s1[0]==s2[i]){
            dp[0][i]=1;
            temp=i;
            break;
        }
    }
    for(int i=temp+1;i<n;i++){
        dp[0][i]=1;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(s1[i]==s2[j]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp;
}

string shortestCommonSupersequence(string str1, string str2) {
    int m=str1.size();
    int n=str2.size();
    vector<vector<int>> dp=makeLcsTable(str1,str2);
    int i=m-1,j=n-1;
    int dpNum=dp[m-1][n-1];
    string ans;
    while(i>=0 && j>=0){
        if(j>0 && dp[i][j-1]==dpNum){
            ans+=str2[j];
            j--;
        }
        else if(i>0 && dp[i-1][j]==dpNum){
            ans+=str1[i];
            i--;
        }
        else if(str1[i]!=str2[j] && i==0 && j==0){
            ans+=str1[i];
            ans+=str2[j];
            i--;
            j--;
        }
        else if(str1[i]==str2[j]){
            ans+=str1[i];
            dpNum--;
            i--;
            j--;
        }
    }
    for(int index=i;index>=0;index--){
        ans+=str1[index];
    }
    for(int index=j;index>=0;index--){
        ans+=str2[index];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    string ans=shortestCommonSupersequence(s1,s2);
    cout<<ans<<endl;
    return 0;
}