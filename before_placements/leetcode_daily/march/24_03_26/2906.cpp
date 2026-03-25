#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int MOD=12345;
    vector<int> prefix_product(m*n,1);
    vector<int> suffix_product(m*n,1);
    long long product=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i*m+j+1<m*n){
                product*=grid[i][j];
                product%=MOD;
                prefix_product[i*m+j+1]=product;
            }
        }
    }      
    product=1;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i*m+j-1>=0){
                product*=grid[i][j];
                product%=MOD;
                suffix_product[i*m+j-1]=product;
            }
        }
    }      
    vector<vector<int>> ans(n,vector<int>(m,1));
    long a=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             a=prefix_product[i*m+j]*suffix_product[i*m+j];
             a%=MOD;
             ans[i][j]=a;
        }
    }
    printArr(prefix_product);
    cout<<"======================"<<endl;
    printArr(suffix_product);
    return ans;
}

int main(){
    return 0;
}