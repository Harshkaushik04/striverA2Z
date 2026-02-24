#include<bits/stdc++.h>
using namespace std;

    string reverseWords(string s) {
    string curr;
    vector<string> arr;
    for(char ch:s){
        if(ch==' '){
            if(curr.size()!=0) arr.emplace_back(curr);
            curr.clear();
        }
        else curr+=ch;
    }
    if(curr.size()!=0) arr.emplace_back(curr);
    reverse(arr.begin(),arr.end());
    string ans;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(i!=n-1){
            ans+=arr[i];
            ans+=" ";
        }
        else ans+=arr[i];
    }
    return ans;
}