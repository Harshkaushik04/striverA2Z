#include<iostream>
#include<cmath>

using namespace std;

int INT_MAX=pow(2,31)-1;
int INT_MIN=-pow(2,31);

    int reverse(int x) {
        int digit;
        long ans = 0;
        while (x!=0) {
            digit = x% 10;
            ans=ans*10+digit;
            x/=10;
        }
        if (ans > INT_MAX || ans < INT_MIN) {
            ans = 0;
        }
        return ans;
    }
    int main(){
        cout<<reverse(7730);
        return 0;
    }
