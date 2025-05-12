#include<iostream>
#include<vector>
using namespace std;

void printMatrix(vector<vector<int>>& matrix){
    int numRows=matrix.size();
    int numColumns=matrix[0].size();
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numColumns;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

//given n*n matrix
void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int temp,temp1;
    int newi,newj;
    int t=4;
    int tempNew;
    for(int i=0;i<n/2;i++){
        temp=matrix[i][i];
        newi=i;
        for(int j=i;j<n-i-1;j++){
            newi=i;
            newj=j;
            t=4;
            temp=matrix[newi][newj];
            while(t--){
                temp1=matrix[newj][n-newi-1];
                matrix[newj][n-newi-1]=temp;
                temp=temp1;
                tempNew=newi;
                newi=newj;
                newj=n-tempNew-1;
            }
        }
    }
}

int main(){
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>>& _matrix=matrix;
    rotate(_matrix);
    printMatrix(_matrix);
    return 0;
}