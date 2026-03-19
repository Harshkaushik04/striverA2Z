#include<bits/stdc++.h>
using namespace std;

class Fancy {
public:
    int MOD=1e9+7;
    vector<double> actualValues;
    long add=0;
    long mult=1;
    int power(long a,long b){
        if(b==0) return 1;
        int half=power(a,b/2);
        int result=((long)half*half)%MOD;
        if(b%2==1){
            result=((long)result*a)%MOD;
        }
        return result;
    }
    Fancy() {

    }
    
    void append(int val) {
        long temp=val;
        if(temp<add) temp+=MOD;
        temp-=add;
        temp%=MOD;
        temp*=power(mult,MOD-2);
        temp%=MOD;
        actualValues.emplace_back(temp);
    }
    
    void addAll(int inc) {
        add+=inc;
        add%=MOD;
    }
    
    void multAll(int m) {
        add*=m;
        add%=MOD;
        mult*=m;
        mult%=MOD;
    }
    
    int getIndex(int idx) {
        int ssize=actualValues.size();
        if(ssize<=idx) return -1;
        long temp=actualValues[idx];
        temp*=mult;
        temp%=MOD;
        temp+=add;
        temp%=MOD;
        return temp;
    }
};

int main(){
    Fancy fancy = Fancy();
    fancy.append(5);
    fancy.append(4);
    fancy.append(3);
    fancy.addAll(3);
    fancy.multAll(2);
    cout<<fancy.getIndex(2)<<endl;
    return 0;
}
