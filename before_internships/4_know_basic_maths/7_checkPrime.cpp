#include<iostream>
#include<cmath>

using namespace std;

bool checkPrime(int n){
    int sqrt_n=sqrt(n);
    if(n==2){
        return true;
    }
    for(int i=2;i<=sqrt_n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    cout<<checkPrime(97)<<endl;
    return 0;
}