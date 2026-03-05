#include<bits/stdc++.h>
using namespace std;

int numSpecial(vector<vector<int>>& mat) {
    int m=mat.size();
    int n=mat[0].size();
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                bool flag=true;
                for(int k=0;k<n;k++){
                    if(j!=k && mat[i][k]==1){
                        flag=false;
                        break;
                    }
                }
                if(!flag) break;
                for(int k=0;k<m;k++){
                    if(i!=k && mat[k][j]==1){
                        flag=false;
                        break;
                    }
                }
                if(!flag) break;
                if(flag) ans++;
            }
        }
    }
    return ans;
}

int main(){
    return 0;
}