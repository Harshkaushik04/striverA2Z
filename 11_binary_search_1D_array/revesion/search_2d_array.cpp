#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    int m=matrix[0].size();
    int l=0,h=m*n-1;
    int mid=(l+h)/2;
    while(l<=h){
        int i=mid/n;
        int j=mid%n;
        if(matrix[i][j]==target) return true;
        else if(matrix[i][j]>target){
            h=mid-1;
            mid=(l+h)/2;
        }
        else if(matrix[i][j]<target){
            l=mid+1;
            mid=(l+h)/2;
        }
    }
    return false;
}