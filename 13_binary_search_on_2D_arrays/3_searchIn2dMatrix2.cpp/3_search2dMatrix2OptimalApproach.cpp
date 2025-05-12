#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int arrSize=matrix.size(),arrSize2=matrix[0].size();
    int row=0,column=arrSize2-1;
    while(row<arrSize && column>=0){
        cout<<row<<","<<column<<":"<<matrix[row][column]<<endl;
        if(matrix[row][column]==target){
            return true;
        }
        else if(matrix[row][column]>target){
            column--;
        }
        else{
            row++;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    bool ans=searchMatrix(matrix,5);
    return 0;
}