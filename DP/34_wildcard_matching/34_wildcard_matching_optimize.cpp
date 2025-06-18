#include<bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
    int m=s.size(),n=p.size();
    vector<int> current(n+1,-1);
    vector<int> last(n+1,-1);
    bool flag=false;
    int index=0;
    for(int k=0;k<n;k++){
        if(p[k]!='*'){
            index=k;
            flag=true;
            break;
        }
    }
    if(flag){
        for(int k=0;k<index;k++) last[k+1]=true;
        for(int k=index;k<n;k++) last[k+1]=false;
    }
    else{
        for(int k=0;k<n;k++) last[k+1]=true;
    }
    current[0]=false;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(p[j-1]=='*') current[j]=last[j]||current[j-1];
            else if(p[j-1]=='?') current[j]=last[j-1];
            else{
                if(s[i-1]==p[j-1]) current[j]=last[j-1];
                else current[j]=false;
            }
        }
        last=current;
    }
    return last[n];
}