#include<bits/stdc++.h>
using namespace std;

static bool comp(int a,int b){
    int popcount_a=__builtin_popcount(a);
    int popcount_b=__builtin_popcount(b);
    if(popcount_a<popcount_b){
        return true;
    }
    else if(popcount_b<popcount_a){
        return false;
    }
    else{
        return (b>a);
    }
}

vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(),arr.end(),comp);
    return arr;
}

int main(){
    return 0;
}