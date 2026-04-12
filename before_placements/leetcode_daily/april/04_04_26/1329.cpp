#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();
    vector<vector<int>> diagonalMatrix(m+n,vector<int>(max(m,n),-1));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int alpha=i-j+1;
            int i_dash=m-alpha;
            int j_dash=-1;
            if(alpha>=0) j_dash=m-i-1;
            else j_dash=n-j-1;
            diagonalMatrix[i_dash][j_dash]=mat[i][j];
        }
    }
    vector<vector<int>> specialMatrix;
    int beta=max(m,n);
    int counter=-1;
    for(int i=0;i<m+n;i++){
        specialMatrix.emplace_back(vector<int>{});
        counter++;
        for(int j=0;j<beta;j++){
            if(diagonalMatrix[i][j]!=-1) specialMatrix[counter].emplace_back(diagonalMatrix[i][j]);
        }
    }
    for(int i=0;i<m+n;i++){
        sort(specialMatrix[i].rbegin(),specialMatrix[i].rend());
    }
    counter=-1;
    for(int i=0;i<m+n;i++){
        counter++;
        int j_counter=0;
        for(int j=0;j<beta;j++){
            if(diagonalMatrix[i][j]!=-1){
                diagonalMatrix[i][j]=specialMatrix[counter][j_counter];
                j_counter++;
            }
        }
    }
    for(int i_dash=0;i_dash<m+n;i_dash++){
        for(int j_dash=0;j_dash<beta;j_dash++){
            if(diagonalMatrix[i_dash][j_dash]==-1) continue;
            if(m-i_dash>=0){
                int i=m-j_dash-1;
                int j=i_dash-j_dash;
                mat[i][j]=diagonalMatrix[i_dash][j_dash];
            }
            else{
                int j=n-j_dash-1;
                int i=m+n-i_dash-j_dash-2;
                mat[i][j]=diagonalMatrix[i_dash][j_dash];
            }
        }
    }
    return mat;
}
