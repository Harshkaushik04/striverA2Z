#include<iostream>

using namespace std;

void printNos(int n) {
    if(n<1){
        return;
    }
    cout<<n<<" ";
    printNos(n-1);
}

int main(){
    printNos(50);
    return 0;
}