#include<bits/stdc++.h>
using namespace std;

string numberToBinaryString(int n){
    int temp = n;
    int len=log2(n);
    string ans(len,'0');
    while(temp!=0){
        int m=log2(temp);
        temp-=pow(2,m);
        ans[m]='1';
    }
    return ans;
}

int binaryStringToNumber(string& s){
    int ssize=s.size();
    int ans=0;
    for(int i=0;i<ssize;i++){
        if(s[i]=='1') ans+=pow(2,i);
    }
    return ans;
}

int bitwiseComplement(int n) {
    string binaryString = numberToBinaryString(n);
    int ssize=binaryString.size();
    for(int i=0;i<ssize;i++){
        if(binaryString[i]=='0') binaryString[i]='1';
        else if(binaryString[i]=='1') binaryString[i]='0';
    }
    return binaryStringToNumber(binaryString);
}