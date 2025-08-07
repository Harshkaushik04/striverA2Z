#include<bits/stdc++.h>
using namespace std;
/*
Question: Given an array of stock prices, at time 0, 1, 2, etc. find the maximum time
interval for which the stock’s price has fallen.
*/

/*
arr=[2,5,2,432,5,4352,123,34,5,53]
maxi=0
iterate over whole array
store a prev variable if current val<prev val =>stock is falling 
also make a counter variable which calculates the continuous falling of stock, whenever stock falls, increment it
and whenevr stock starts increasing, firstly do maxi=max(maxi,counter) and reinitialise counter to 0
*/

int max_time_falling_stock(vector<int> stocks){
    int maxi=0;
    int counter=0;
    int ssize=stocks.size();
    if(ssize==0) return -1;
    if(ssize==1) return 0;
    int prev=stocks[0];
    for(int i=1;i<ssize;i++){
        if(stocks[i]<prev) counter++;
        else{
            maxi=max(maxi,counter+1);
            counter=0;
        }
        prev=stocks[i];
    }
    maxi=max(maxi,counter+1);
    return maxi;
}