#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n){
    long temp=abs((long)n);
    double num=x;
    if(n==0) return 1;
    vector<int> instructions;
    while(temp!=1){
        if(temp%2==0){
            instructions.emplace_back(2);
            temp/=2;
        }
        else{
            instructions.emplace_back(1);
            temp--;
        }
    }
    int m=instructions.size();
    for(int i=m-1;i>=0;i--){
        if(instructions[i]==1) num*=x;
        else num*=num;
    }
    if(n<0) return 1/num;
    return num;
}