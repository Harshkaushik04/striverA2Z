#include<iostream>
#include<vector>

using namespace std;

vector<int> lcmAndGcd(int a, int b) {
    //Euclidean theorm: gcd(a,b)=gcd(a-b,b) such that a>b
    int bigger=a,smaller=b;
    int temp;
    if(b>a){
        bigger=b;
        smaller=a;
    }
    while(smaller!=0){
        temp=smaller;
        smaller=bigger%smaller;
        bigger=temp;
    }
    int gcd=bigger;
    int lcm=a*b/gcd;
    return {lcm,gcd};
}

int main(){
    cout<<"lcm:"<<lcmAndGcd(98,28)[0]<<endl;
    cout<<"gcd:"<<lcmAndGcd(98,28)[1]<<endl;
    return 0;
}