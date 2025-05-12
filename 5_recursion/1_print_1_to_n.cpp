#include<iostream>

using namespace std;

void printNos(int n) {
    if(n<1){
        return;
    }
    printNos(n-1);
    cout<<n<<" ";
}

int main(){
    printNos(50);
    return 0;
}