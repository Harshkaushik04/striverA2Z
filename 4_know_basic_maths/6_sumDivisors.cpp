#include<iostream>
#include<cmath>
#include<vector>

using namespace std; 

int sumDivisorsOneNumber(int n){
    int sqrt_n=sqrt(n);
    int ans=0;
    for(int i=1;i<=sqrt_n;i++){
        if(n%i==0){
            ans+=i;
            if(n/i!=i){
                ans+=n/i;
            }
        }
    }
    return ans;
}

int sumOfDivisors(int n) {
    int final_ans=0;
    for(int i=1;i<=n;i++){
        final_ans+=sumDivisorsOneNumber(i);
    }
    return final_ans;
}

int main(){
    cout<<sumOfDivisors(4)<<endl;
    return 0;
}