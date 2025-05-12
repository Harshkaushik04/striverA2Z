#include<iostream>
#include<cmath>

using namespace std;

int sum=0;
int sumOfSeries(int n){
    if(n<1){
        return 0;
    }
    sum=pow(n,3)+sumOfSeries(n-1);
    return sum;
}

int main(){
    cout<<sumOfSeries(6)<<endl;
    return 0;
}