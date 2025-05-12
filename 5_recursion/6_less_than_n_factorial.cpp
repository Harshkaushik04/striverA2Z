#include<iostream>
#include<vector>

using namespace std;

vector<long long> factorialNumbers(long long n) {
        vector<long long> numbers;
        long long factorial=1;
        int i=1;
        while(factorial<=n){
            factorial*=i;
            if(factorial<=n){
             numbers.emplace_back(factorial);   
            }
            i++;
        }
        return numbers;
    }

int main(){
    vector<long long> numbers=factorialNumbers(220);
    for(int i=0;i<numbers.size();i++){
        cout<<numbers[i]<<" ";
    }
    cout<<endl;
    return 0;
}