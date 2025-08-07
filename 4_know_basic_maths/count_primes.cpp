#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    if(n<=2) return 0;
    int ans=0;
    vector<int> primes(n+1,1);
    primes[0]=0;
    primes[1]=0;
    for(int i=2;i*i<n;i++){
        if(primes[i]==1){
            for(int j=i*i;j<n;j+=i){
                primes[j]=0;
            }
        }
    }
    for(int i=1;i<n;i++){
        if(primes[i]==1) ans++;
    }
    return ans;
}