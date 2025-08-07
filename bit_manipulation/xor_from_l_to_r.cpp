#include<bits/stdc++.h>
using namespace std;

int findXOR(int l, int r) {
    if(l==r) return l;
    int ans1=0,ans2=0;
    if(r%4==1) ans1=1;
    else if(r%4==2) ans1=r+1;
    else if(r%4==3) ans1=0;
    else ans1=r;
    if(l==1) return ans1;
    l-=1;
    if(l%4==1) ans2=1;
    else if(l%4==2) ans2=l+1;
    else if(l%4==3) ans2=0;
    else ans2=l;
    return ans1^ans2;
}