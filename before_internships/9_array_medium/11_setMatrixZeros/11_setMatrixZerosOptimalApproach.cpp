//space complexity O(1)
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

void setZeroes(vector<vector<int>>& matrix) {
    int numRows=matrix.size();
    int numColumns=matrix[0].size();
    int row0=1;
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numColumns;j++){
            if(matrix[i][j]==0){
                matrix[0][j]=0;
                if(i!=0){
                    matrix[i][0]=0;
                }
                else{
                    row0=0;
                }
            }
        }
    }
    for(int i=0;i<numRows;i++){
        if(i!=0){
            if(matrix[i][0]==0){
                for(int j=0;j<numColumns;j++){
                    matrix[i][j]=0;
                }
            }
        }
    }
    for(int i=0;i<numColumns;i++){
        if(matrix[0][i]==0){
            for(int j=0;j<numRows;j++){
                matrix[j][i]=0;
            }
        }
    }
    if(row0==0){
        for(int j=0;j<numColumns;j++){
            matrix[0][j]=0;
        }
    }
}

int main(){
    vector<vector<int>> matrix={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<vector<int>>& _matrix=matrix;
    setZeroes(_matrix);
    return 0;
}