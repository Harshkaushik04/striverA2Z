#include<bits/stdc++.h>
using namespace std;

bool successRotateNumber(int n){
    int temp=n;
    bool flag=false;
    while(temp!=0){
        int digit=temp%10;
        temp/=10;
        if(digit==3||digit==4|| digit==7) return false;
        if(digit==2||digit==5||digit==6||digit==9) flag=true;
    }   
    if(!flag) return false;
    return true;
}

int rotatedDigits(int n) {
    int ans=0;
    for(int i=1;i<=n;i++){
        if(successRotateNumber(i)) ans++;
    }
    return ans;
}