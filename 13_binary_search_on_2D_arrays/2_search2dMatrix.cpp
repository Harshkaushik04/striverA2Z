#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int arrSize=matrix.size(),arrSize2=matrix[0].size();
    int low=0,high=arrSize*arrSize2-1,mid=(low+high)/2;
    int midi,midj;
    while(low<=high){
        midi=mid/arrSize2;
        midj=mid-midi*arrSize2;
        if(matrix[midi][midj]==target){
            return true;
        }
        else if(matrix[midi][midj]>target){
            high=mid-1;
            mid=(low+high)/2;
        }
        else{
            low=mid+1;
            mid=(low+high)/2;
        }
    }
    return false;
}