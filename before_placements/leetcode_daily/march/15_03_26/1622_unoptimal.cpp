#include<bits/stdc++.h>
using namespace std;

class Fancy {
public:
    int MOD=1e9+7;
    vector<int> actualValues;
    Fancy() {

    }
    
    void append(int val) {
        actualValues.emplace_back(val);
    }
    
    void addAll(int inc) {
        int ssize=actualValues.size();
        for(int i=0;i<ssize;i++){
            long temp=((long)actualValues[i]+inc)%MOD;
            actualValues[i]=temp;
        }
    }
    
    void multAll(int m) {
        int ssize=actualValues.size();
        for(int i=0;i<ssize;i++){
            long temp=((long)actualValues[i]*m)%MOD;
            actualValues[i]=temp;
        }
    }
    
    int getIndex(int idx) {
        int ssize=actualValues.size();
        if(ssize<=idx) return -1;
        return actualValues[idx];
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
