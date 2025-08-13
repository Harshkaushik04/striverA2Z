#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    int count=0;
    int l=0,r=0;
    unordered_map<char,int> mpp;
    int i,j;
    for(char ch:t){
        if(mpp.find(ch)==mpp.end()) mpp[ch]=1;
        else mpp[ch]++;
    }
    int mini=INT32_MAX;
    int t_char=mpp.size();
    int n=s.size(); 
    int saved_i=0,saved_j=1e8;
    while(l<=r && r<n){
        if(t_char>count){
            if(mpp.find(s[r])!=mpp.end()) mpp[s[r]]--;
            else mpp[s[r]]=-1;
            if(mpp[s[r]]==0) count++;
            while(t_char==count){
                i=l;
                j=r;
                if(saved_j-saved_i+1>j-i+1){
                    saved_i=i;
                    saved_j=j;
                }
                mini=min(mini,r-l+1);
                mpp[s[l]]++;
                if(mpp[s[l]]==1) count--;
                l++;
            }
            r++;
        }
    }
    if(mini==INT32_MAX) return "";
    return s.substr(saved_i,saved_j-saved_i+1);
}   