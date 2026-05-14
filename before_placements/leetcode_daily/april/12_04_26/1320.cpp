#include<bits/stdc++.h>
using namespace std;

int dist(char ch1,char ch2,unordered_map<char,pair<int,int>>& mpp){
    return abs(mpp[ch1].first-mpp[ch2].first)+abs(mpp[ch1].second-mpp[ch2].second);
}

int f(int i,char left_letter,char right_letter,string& word,int n,vector<vector<vector<int>>>& dp,unordered_map<char,pair<int,int>>& mpp){
    if(dp[i][left_letter-'A'][right_letter-'A']!=-1) return dp[i][left_letter-'A'][right_letter-'A'];
    if(i==n-1){
        int left_distance=dist(left_letter,word[i],mpp);
        int right_distance=dist(right_letter,word[i],mpp);
        dp[i][left_letter-'A'][right_letter-'A']=min(left_distance,right_distance);
        return dp[i][left_letter-'A'][right_letter-'A'];
    }
    int left_distance=dist(left_letter,word[i],mpp)+f(i+1,word[i],right_letter,word,n,dp,mpp);
    int right_distance=dist(right_letter,word[i],mpp)+f(i+1,left_letter,word[i],word,n,dp,mpp);
    dp[i][left_letter-'A'][right_letter-'A']=min(left_distance,right_distance);
    return dp[i][left_letter-'A'][right_letter-'A'];
}

int minimumDistance(string word) {
    unordered_map<char,pair<int,int>> mpp;
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            int add=6*i+j;
            mpp['A'+add]=pair<int,int>{i,j};
        }
    }
    int n=word.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(26,vector<int>(26,-1)));
    int ans=INT32_MAX;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            int temp=f(0,i+'A',j+'A',word,n,dp,mpp);
            if(temp>=0) ans=min(ans,temp);
        }
    }
    return ans;
}

int main(){
    return 0;
}