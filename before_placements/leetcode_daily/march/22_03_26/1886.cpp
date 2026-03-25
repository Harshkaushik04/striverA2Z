#include<bits/stdc++.h>
using namespace std;
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    int n=mat.size();
    bool flag=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(target[i][j]!=mat[j][n-i-1]){
                flag=false;
                break;
            }
        }
    }
    if(flag) return true;
    flag=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(target[i][j]!=mat[n-i-1][n-j-1]){
                flag=false;
                break;
            }
        }
    }
    if(flag) return true;
    flag=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(target[i][j]!=mat[n-j-1][i]){
                flag=false;
                break;
            }
        }
    }
    if(flag) return true;
    flag=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(target[i][j]!=mat[i][j]){
                flag=false;
                break;
            }
        }
    }
    if(flag) return true;
    return false;
}