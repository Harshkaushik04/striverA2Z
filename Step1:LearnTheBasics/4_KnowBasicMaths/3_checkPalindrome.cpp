#include<iostream>
#include<cmath>

using namespace std;

// int INT_MAX=pow(2,31)-1;
// int INT_MIN=-pow(2,31);

int reverse(int x) {
        int digit;
        long ans = 0;
        while (x!=0) {
            digit = x% 10;
            ans=ans*10+digit;
            x/=10;
        }
        return ans;
}
bool isPalindrome(int x) {
        bool ans=true;
        if(reverse(x)==x && x>=0){
            ans=true;
        }
        else{
            ans=false;
        }
        return ans;
    }
int main(){
    cout<<isPalindrome(203302)<<endl;
    return 0;
}