#include<iostream>
#include<cmath>
#include<vector>

using namespace std; 

bool checkArmstrongNumber(int n){
    int digit;
    int numDigits=0;
    vector<int> digits;
    int original_n=n;
    while(n!=0){
        digit=n%10;
        if(digit!=0){
            numDigits+=1;
        }
        digits.emplace_back(digit);
        n/=10;
    }
    long long final_ans=0;
    for(int i=0;i<numDigits;i++){
        final_ans+=pow(digits[i],numDigits);
    }
    if(final_ans==original_n){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    cout<<checkArmstrongNumber(371)<<endl;
    return 0;
}