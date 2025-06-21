#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> current={{0,0,0},{0,0,0}};
    int temp1,temp2,temp3,temp4,temp5,temp6;
    for(int i=n-1;i>=0;i--){
        temp1=max(current[1][0],current[0][1]-prices[i]); //can buy,num_buys=0
        temp2=current[0][0]; //not buy,num_buys=0
        temp3=max(current[1][1],current[0][2]-prices[i]); //can buy,num_buys=1
        temp4=max(current[0][1],current[1][1]+prices[i]); //not buy,num_buys=1
        temp5=current[1][2]; //cam buy,num_buys=2
        temp6=max(current[0][2],current[1][2]+prices[i]); //not buy,num_buys=2
        current[1][0]=temp1;
        current[0][0]=temp2;
        current[1][1]=temp3;
        current[0][1]=temp4;
        current[1][2]=temp5;
        current[0][2]=temp6;
    }
    return current[1][0];
}

//4 variables:
// int maxProfit(vector<int>& prices) {
//     int n=prices.size();
//     vector<vector<int>> current={{0,0,0},{0,0,0}};
//     int temp1,temp3,temp4,temp6;
//     for(int i=n-1;i>=0;i--){
//         temp1=max(current[1][0],current[0][1]-prices[i]); //can buy,num_buys=0
//         temp3=max(current[1][1],current[0][2]-prices[i]); //can buy,num_buys=1
//         temp4=max(current[0][1],current[1][1]+prices[i]); //not buy,num_buys=1
//         temp6=max(current[0][2],current[1][2]+prices[i]); //not buy,num_buys=2
//         current[1][0]=temp1;
//         current[1][1]=temp3;
//         current[0][1]=temp4;
//         current[0][2]=temp6;
//     }
//     return current[1][0];
// }