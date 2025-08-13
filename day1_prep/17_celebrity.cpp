#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>>& M){
    int n=M.size();
    int low=0,high=n-1;
    while(low<high){
        if(M[low][high]==1) low++;
        else if(M[high][low]==1) high--;
        else{
            low++;
            high--;
        } 
    }
    if(low!=high) return -1;
    else{
        for(int i=0;i<n;i++){
            if(M[low][i]!=0) return -1;
        }
        for(int i=0;i<n;i++){
            if(M[i][low]!=1 && i!=low) return -1;
        }
    }
    return low;
}