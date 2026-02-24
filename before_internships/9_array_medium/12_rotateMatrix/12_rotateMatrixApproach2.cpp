#include<iostream>
#include<vector>
#include<algorithm>
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
    //transpose
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //reverse each row
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main(){
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>>& _matrix=matrix;
    rotate(_matrix);
    printMatrix(_matrix);
    return 0;
}