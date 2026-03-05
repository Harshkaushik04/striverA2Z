#include<bits/stdc++.h>
using namespace std;
//unoptimized tc
bool hasAllCodes(string s, int k) {
    int sSize=s.size();
    int len=0;
    set<string> codes;
    for(int i=0;i<sSize-k+1;i++){
        string sub_string=s.substr(i,k);
        if(codes.find(sub_string)==codes.end()){
            codes.insert(sub_string);
            len++;
        }
        if(len==pow(2,k)) return true;
    }
    return false;
}