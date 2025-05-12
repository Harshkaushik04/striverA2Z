#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
//in optimized approach, findMthPower function is optimized

int findMthPower(int n,int m){
    int result=1;
    for(int i=0;i<m;i++){
        if(result*(long long)n<=INT32_MAX){
            result*=n;
        }
        else{
            return -1;
        }
    }
    return result;
}

int nthRoot(int n, int m) {
    int low=0,high=n,mid=(low+high)/2;
    int temp;
    while(low<=high){
        temp=findMthPower(mid,m);
        if(temp!=-1){
            if(temp==n){
                return mid;
            }
            else if(temp<n){
                low=mid+1;
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
    return -1;
}

int main(){
    int ans=nthRoot(9,2);
    cout<<ans<<endl;
    return 0;
}