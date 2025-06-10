#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    int prev2=0,prev=1,temp;
    for(int i=2;i<=n;i++){
        temp=prev;
        prev=prev2+prev;
        prev2=temp;
    }
    return prev;
}