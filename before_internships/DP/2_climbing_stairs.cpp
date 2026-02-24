#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    if(n==1) return 1;
    if(n==2) return 2;
    int prev2=1,prev=2,temp;
    for(int i=0;i<n-2;i++){
        temp=prev;
        prev=prev+prev2;
        prev2=temp;
    } 
    return prev;
}