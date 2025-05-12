#include<iostream>
#include<String>

using namespace std;

//itterative approach

bool isPalindrome(string s){
    int i=0,j=s.size()-1;
    while(j>i){
        while(j>i && !isalnum(s[i])){
            i++;
        }
        while(j>i && !isalnum(s[j])){
            j--;
        }
        if(_tolower(s[i])!=_tolower(s[j])){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    cout<<isPalindrome("new")<<endl;;
    return 0;
}