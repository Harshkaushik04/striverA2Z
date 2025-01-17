#include<iostream>

using namespace std;

int countTotalDigits(int n){
    int digit;
    int ans=0;
    while(n!=0){
        digit=n%10;
        if(digit!=0){
            ans+=1;
        }
        n/=10;
    }
    return ans;
}

int main(){
    cout<<countTotalDigits(87432)<<endl;
    return 0;
}