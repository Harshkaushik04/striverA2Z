#include<bits/stdc++.h>
using namespace std;

/*
[0,1,||0||,2,||1,0,1,||3,2,||1||,2,1]
[0,1,0,2,1,0,1,3,2,1,2,1]
[0,1,1,2,2,2,2,3,3,3,3,3]
[3,3,3,3,3,3,3,3,2,2,2,1]
*/

int trap(vector<int>& height) {
    int n=height.size();
    vector<int> prefixMax(n,-1);
    vector<int> suffixMax(n,-1);
    int maxi=-1;
    for(int i=0;i<n;i++){
        maxi=max(maxi,height[i]);
        prefixMax[i]=maxi;
    }
    maxi=-1;
    for(int i=n-1;i>=0;i--){
        maxi=max(maxi,height[i]);
        suffixMax[i]=maxi;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=min(prefixMax[i]-height[i],suffixMax[i]-height[i]);
    }
    return ans;
}