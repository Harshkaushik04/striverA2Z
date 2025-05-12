#include<iostream>
using namespace std;
int ceilDivision(int m,int n){
    if(m%n==0){
        return m/n;
    }
    else{
        return m/n+1;
    }
}
int main(){
    cout<<ceilDivision(4,1)<<endl;
}