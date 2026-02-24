#include<bits/stdc++.h>
using namespace std;
long handle_string(string& s,int flag){
    long ans=0;
    if(s=="") return 0;
    else{
        int n=s.size();
        int i=0;
        while(i<n){
            ans=ans*10+(long)(s[i]-'0');
            if(ans>(long)INT32_MAX+1 && flag==-1) return (long)INT32_MAX+1;
            else if(ans>(long)INT32_MAX && flag==1) return (long)INT32_MAX;
            i++;
        }
        return ans;
    }
}

int myAtoi(string s) {
    int n=s.size();
    int i=0;
    unordered_map<char,int> numbers;
    string ans;
    for(int i=0;i<10;i++){
        numbers['0'+i]=1;
    }
    while(i<n && (s[i]==' ')) i++;
    int flag=1;
    if(s[i]=='-'){
        flag=-1;
        i++;
    }
    else if(s[i]=='+') i++;
    while(i<n){
        if(numbers.find(s[i])==numbers.end()) return flag*handle_string(ans,flag);
        else{
            ans+=s[i];
            i++;
        } 
    }
    return flag*handle_string(ans,flag);
}