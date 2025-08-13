#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
int n=s.size();
int maxi=-1,depth=0;
for(int i=0;i<n;i++){
    if(s[i]=='(') depth++;
    else if(s[i]==')') depth--;
    if(depth>maxi) maxi=depth;
}           
return maxi;
}