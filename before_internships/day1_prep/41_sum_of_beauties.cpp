#include<bits/stdc++.h>
using namespace std;

// make vector<int>: maxi,mini frequency arrays,unordered_map<char,int>: general count of all characters
// vector<pair<int,char>>: general count of all characters

/*
vector<unordered_map<char,int>> 
*/

// int max_and_min(int i,int j,vector<unordered_map<char,int>>& prefix_arr){
//     int maxi=-1,mini=INT32_MAX;
//     for(int k=0;k<26;k++){
//         if(prefix_arr[j+1]['a'+k]-prefix_arr[i]['a'+k]!=0){
//             maxi=max(maxi,prefix_arr[j+1]['a'+k]-prefix_arr[i]['a'+k]);
//             mini=min(mini,prefix_arr[j+1]['a'+k]-prefix_arr[i]['a'+k]);
//         }
//     }
//     return maxi-mini;
// }

int beautySum(string s){
    int n=s.size();
    vector<int> mpp(26,0);
    vector<vector<int>> prefix_arr;
    prefix_arr.emplace_back(mpp);
    for(int i=0;i<n;i++){
        char ch=s[i];
        mpp[ch-'a']++;
        prefix_arr.emplace_back(mpp);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int maxi=-1,mini=INT32_MAX;
            for(int k=0;k<26;k++){
                if(prefix_arr[j+1][k]-prefix_arr[i][k]!=0){
                    maxi=max(maxi,prefix_arr[j+1][k]-prefix_arr[i][k]);
                    mini=min(mini,prefix_arr[j+1][k]-prefix_arr[i][k]);
                }
            }
            ans+=(maxi-mini);
        }
    }
    return ans;
}