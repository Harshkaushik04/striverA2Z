#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int>& height) {
    // Code here
    int n=height.size();
    if(n==1) return 0;
    if(n==2) return abs(height[1]-height[0]);
    int prev2=0,prev=abs(height[1]-height[0]),temp; //prev2=f(i-2),prev=f(i-1)
    for(int i=2;i<n;i++){
        temp=prev;
        prev=min(prev+abs(height[i]-height[i-1]),prev2+abs(height[i]-height[i-2]));
        prev2=temp;
    }
    return prev;
}