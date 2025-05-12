#include<iostream>
#include<vector>

using namespace std;

//given numrows>=1
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result={{1},{1,1}};
    vector<int> temp;
    int tempSum;
    int resultSize=2;
    if(numRows==1){
        return {{1}};
    }
    else if(numRows==2){
        return result;
    }
    else{
        for(int i=0;i<numRows-2;i++){
            temp=vector<int>(1,1);
            for(int j=0;j<resultSize-1;j++){
                tempSum=result[resultSize-1][j]+result[resultSize-1][j+1];
                temp.emplace_back(tempSum);
            }
            temp.emplace_back(1);
            result.emplace_back(temp);
            resultSize++;
        }
    }
    return result;
}

int main(){
    return 0;
}