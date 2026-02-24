#include<iostream>
#include<vector>

using namespace std;

int findMthPower(int n,int m){
    int result=1;
    while(m>0){
        if(m%2==1){
            if(result*(long long)n<=INT32_MAX){
                result*=n;
            }
            else{
                return -1;
            }
            m--;
        }
        else{
            if(n*(long long)n<=INT32_MAX){
                n*=n;
            }
            else{
                return -1;
            }
            m/=2;
        }
    }
    return result;
}

int nthRoot(int n, int m) {
    int low=0,high=n,mid=(low+high)/2;
    int temp;
    while(low<=high){
        temp=findMthPower(mid,m);
        // cout<<temp<<endl;
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