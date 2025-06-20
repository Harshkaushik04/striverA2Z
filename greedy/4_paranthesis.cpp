#include<bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
    int maxi=0,mini=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            maxi--;
            mini--;
        }
        else if(s[i]==')'){
            maxi++;
            mini++;
        }
        else{
            mini--;
            maxi++;
        }
        if(mini>0) return false;
        if(maxi>0) maxi=0;
    }
    return maxi==0;
}