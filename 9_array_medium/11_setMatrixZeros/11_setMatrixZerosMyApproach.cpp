#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int numRows=matrix.size();
    int numColumns=matrix[0].size();
    vector<int> rowZero,columnZero;
    for(int i=0;i<numColumns;i++){
        for(int j=0;j<numRows;j++){
            if(matrix[j][i]==0){
                rowZero.emplace_back(j);
                columnZero.emplace_back(i);
            }
        }
    }
    // cout<<"hi"<<endl;
    for(int index:rowZero){
        for(int i=0;i<numColumns;i++){
            matrix[index][i]=0;
        }
    }
    for(int index:columnZero){
        for(int i=0;i<numRows;i++){
            matrix[i][index]=0;
        }
    }
}

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

int main(){
    vector<vector<int>> matrix={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<vector<int>>& _matrix=matrix;
    setZeroes(_matrix);
    printMatrix(_matrix);
    return 0;
}