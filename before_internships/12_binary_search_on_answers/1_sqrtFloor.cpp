#include<iostream>
#include<vector>

using namespace std;


int findSquare(int n){
    int result=1;
    if(n*(long long)n<=INT32_MAX){
        result=n*n;
        return result;
    }
    else{
        return -1;
    }
}

int floorSqrt(int n) {
    int low=0,high=n,mid=(low+high)/2;
    int mini=n;
    int temp;
    while(low<=high){
        temp=findSquare(mid);
        if(temp!=-1){
            if(temp<=n){
                low=mid+1;
                mini=mid;
                mid=(low+high)/2;
            }
            else{
                high=mid-1;
                mid=(low+high)/2;
            }
        }
        else{
            high=mid-1;
            mid=(low+high)/2;
        }
    }
    return mini;
}