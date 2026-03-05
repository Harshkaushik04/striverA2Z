#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int concatenatedBinary(int n) {
    ll ans=0;
    ll MOD=1e9+7;
    ll ongoingAddition=1;
    int power=(int)log2(n)+1;
    for(ll i=n;i>=1;i--){
        ll addition=i*ongoingAddition;
        ans+=addition;
        ans%=MOD;
        ongoingAddition=ongoingAddition<<power;
        if(!(i&(i-1))){
            power--;
        }
        ongoingAddition%=MOD;
    }
    return ans;
}