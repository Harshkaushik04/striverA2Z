#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    unordered_map<int,vector<int>> mpp;
    int m=mat.size();
    int n=mat[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mpp.find(i-j)!=mpp.end()) mpp[i-j].emplace_back(mat[i][j]);
            else mpp[i-j]=vector<int>{mat[i][j]};
        }
    }
    for(pair<const int,vector<int>>& p:mpp){
        sort(p.second.begin(),p.second.end());
    }
    unordered_map<int,int> counter;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(counter.find(i-j)!=counter.end()){
                mat[i][j]=mpp[i-j][counter[i-j]];
                counter[i-j]++;
            }
            else{
                mat[i][j]=mpp[i-j][0];
                counter[i-j]=1;
            }
        }
    }
    return mat;
}