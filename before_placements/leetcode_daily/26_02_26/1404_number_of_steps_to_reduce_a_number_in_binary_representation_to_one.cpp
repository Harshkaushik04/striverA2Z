#include<bits/stdc++.h>
using namespace std;

void addOne(string& s,int& ans){
    int length=size(s);
    if(length==0) return;
    for(int i=length-1;i>=0;i--){
        if(s[i]=='0'){
            s[i]='1';
            ans+=(length-i-1);
            s=s.substr(0,i+1);
            return;
        }
        else if(i!=0 && s[i]=='1'){
            s[i]='0';
        }
        else{ //i==0 && s[i]=='1'
            ans+=size(s);
            s="completed";
            return;
        }
    }
}

int numSteps(string s) {
    if(s=="1") return 0;
    string temp = s;
    int ans=0;
    while(temp!="completed" && temp!="1"){
        if(temp[size(temp)-1]=='0'){
            temp.pop_back();
            ans++;
        }
        else{
            ans++;
            addOne(temp,ans);
        }
    }
    return ans;
}

int main(){
    return 0;
}