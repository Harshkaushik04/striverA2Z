#include<bits/stdc++.h>
using namespace std;

int alpha(int i){
    if(i%2==0) return '0';
    else return '1';
}

int beta(int i){
    if(i%2==1) return '0';
    else return '1';
}

int minFlips(string s) {
    int n=s.size();
    int temp0=0,temp1=0;
    //calculate initially
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(s[i]=='0') temp1++;
            else if(s[i]=='1') temp0++;
        }
        else if(i%2==1){
            if(s[i]=='0') temp0++;
            else if(s[i]=='1') temp1++;
        }
    }
    int ans=min(temp0,temp1);
    int newTemp0=temp0,newTemp1=temp1;
    for(int i=0;i<n;i++){
        cout<<"temp0:"<<temp0<<endl;
        cout<<"temp1:"<<temp1<<endl;
        newTemp0=temp1-(int)(s[i]!=beta(i))+(int)(s[i]!=alpha(n+i-1));
        newTemp1=temp0-(int)(s[i]!=alpha(i))+(int)(s[i]!=beta(n+i-1));
        temp0=newTemp0;
        temp1=newTemp1;
        ans=min(ans,temp0);
        ans=min(ans,temp1);
    }
    cout<<"temp0:"<<temp0<<endl;
    cout<<"temp1:"<<temp1<<endl;
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<minFlips(s)<<endl;
    return 0;
}

/*
actual:


int alpha(int i){
    if(i%2==0) return '0';
    else return '1';
}

int beta(int i){
    if(i%2==1) return '0';
    else return '1';
}

int minFlips(string s) {
    int n = s.size();
    int temp0 = 0, temp1 = 0;
    
    // calculate initially
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            if(s[i] == '0') temp1++;
            else if(s[i] == '1') temp0++;
        }
        else if(i % 2 == 1) {
            if(s[i] == '0') temp0++;
            else if(s[i] == '1') temp1++;
        }
    }
    
    int ans = min(temp0, temp1);
    
    // Slide the window
    for(int i = 0; i < n; i++) {
        // Only use temp0 with alpha, and temp1 with beta
        int newTemp0 = temp0 - (int)(s[i] != alpha(i)) + (int)(s[i] != alpha(n + i));
        int newTemp1 = temp1 - (int)(s[i] != beta(i))  + (int)(s[i] != beta(n + i));
        
        temp0 = newTemp0;
        temp1 = newTemp1;
        
        ans = min(ans, temp0);
        ans = min(ans, temp1);
    }
    
    return ans;
}

*/