#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int a=-1,b=-1,c=-1;
    int ans=0;
    int n=s.size();
    int temp;
    for(int i=0;i<n;i++){
        if(s[i]=='a') a=i;
        else if(s[i]=='b') b=i;
        else if(s[i]=='c') c=i;
        if(a!=-1||b!=-1||c!=-1){
            temp=min(a,b);
            temp=min(temp,c);
            ans+=(temp+1);
        }
    }
    return ans;
}