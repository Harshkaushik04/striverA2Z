#include<iostream>
#include<vector>

using namespace std;

vector<int> frequencyCount(vector<int>& arr) {
    int size=arr.size();
    vector<int> frequency(size,0);
    for(int i=0;i<size;i++){
        frequency[arr[i]-1]+=1;
    }
    return frequency;
}

int main(){
    return 0;
}