#include<iostream>

using namespace std;

void printGfg(int N) {
    if(N<1){
        return;
    }
    cout<<"GFG ";
    printGfg(N-1);
}

int main(){
    printGfg(5);
    return 0;
}