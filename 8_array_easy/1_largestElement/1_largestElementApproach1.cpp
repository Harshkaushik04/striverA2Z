#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int largest(vector<int> arr) {
        return *max_element(arr.begin(),arr.end());
}

int main(){
    return 0;
}