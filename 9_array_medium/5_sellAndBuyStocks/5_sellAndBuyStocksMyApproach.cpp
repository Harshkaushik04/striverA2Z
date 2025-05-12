#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int maxDiff=INT32_MIN;
    int miniLeft=0;
    int miniLeftValue=prices[0];
    int right=0;
    int arrSize=prices.size();
    int tempDiff;
    for(int i=0;i<arrSize;i++){
        right=i;
        if(miniLeftValue>prices[i]){
            miniLeftValue=prices[i];
            miniLeft=i;
        }
        tempDiff=prices[right]-prices[miniLeft];
        if(maxDiff<tempDiff){
            maxDiff=tempDiff;
        }
    }
    return maxDiff;        
}

int main(){
    return 0;
}