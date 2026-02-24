#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int arrSize=matrix.size(),arrSize2=matrix[0].size();
    int low,mid,high;
    for(int i=0;i<arrSize;i++){
        low=0,high=arrSize2-1,mid=(low+high)/2;
        while(low<=high){
            if(matrix[i][mid]==target){
                return true;
            }
            else if(matrix[i][mid]>target){
                high=mid-1;
                mid=(low+high)/2;
            }
            else{
                low=mid+1;
                mid=(low+high)/2;
            }
        }
    }
    return false;
}