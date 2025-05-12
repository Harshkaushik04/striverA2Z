#include<iostream>
#include<vector>
using namespace std;

//without making seperate functions beats 100percent time complexity

int findMaxInColumn(vector<vector<int>> mat,int col){
    int matSize=mat.size();
    int maxi=INT32_MIN;
    int ans=0;
    for(int i=0;i<matSize;i++){
        if(maxi<mat[i][col]){
            ans=i,maxi=mat[i][col];
        }
    }
    return ans;
}

vector<int> findPeakGrid(vector<vector<int>>& mat){
    int matSize=mat.size(),matSize2=mat[0].size();
    int low=0,high=matSize2-1,mid=(low+high)/2;
    int maxInColumn;
    if(matSize==1 && matSize2==1){
        return {0,0};
    }
    else if(matSize2==1){
        return {findMaxInColumn(mat,mid),0};
    }
    while(low<=high){
        maxInColumn=findMaxInColumn(mat,mid);
        if(mid>0 && mid<matSize2-1){
            if(mat[maxInColumn][mid]>mat[maxInColumn][mid-1] && mat[maxInColumn][mid]>mat[maxInColumn][mid+1]){
                return {maxInColumn,mid};
            }
            else if(mat[maxInColumn][mid]<mat[maxInColumn][mid-1]){
                high=mid-1;
                mid=(low+high)/2;
            }
            else{
                low=mid+1;
                mid=(low+high)/2;
            }
        }
        else if(mid==0){
            if(mat[maxInColumn][mid]>mat[maxInColumn][mid+1]){
                return {maxInColumn,mid};
            }
            else{
                low=mid+1;
                mid=(low+high)/2;
            }
        }
        else{
            if(mat[maxInColumn][mid]>mat[maxInColumn][mid-1]){
                return {maxInColumn,mid};
            }
            break;
        }
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> mat={{10,50,40,30,20},{1,500,2,3,4}};
    vector<int> ans=findPeakGrid(mat);
    return 0;
}