#include<bits/stdc++.h>
using namespace std;

string removeExtraSpaces(string& s){
    int n=s.size();
    bool flag=false;
    int start=-1;
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            if(!flag){
                start=i;
                flag=true;
            }
        }
        else{
            if(flag){
                start=-1;
                flag=false;
            }
        }
    }
    if(!flag) return s;
    if(start==0) return "";
    return s.substr(0,start);
}

string decodeCiphertext(string encodedText, int rows) {
    int len=encodedText.size();
    int cols=len/rows;
    map<int,vector<char>> mpp;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(mpp.find(j-i)!=mpp.end()) mpp[j-i].emplace_back(encodedText[i*cols+j]);
            else mpp[j-i]=vector<char>{encodedText[i*cols+j]};
        }
    }
    bool trigger=false;
    string ans;
    for(pair<const int,vector<char>>& p:mpp){
        if(p.first==0) trigger=true;
        if(trigger){
            for(char ch:p.second){
                ans+=ch;
            }
        }
    }
    ans=removeExtraSpaces(ans);
    return ans;
}