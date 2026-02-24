#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
        string s="1";
        for(int i=0;i<n-1;i++){
            int j=0;
            int m=s.size();
            string ans;
            while(j<m){
                int count=0;
                char ch=s[j];
                while(j<m && s[j]==ch){
                    count++;
                    j++;
                } 
                ans+=('0'+count);
                ans+=ch;
            }
            s=ans;
        }
        return s;
    }