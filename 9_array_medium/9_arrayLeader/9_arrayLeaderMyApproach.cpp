#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> leaders(vector<int>& arr) {
    int arrSize=arr.size();
    int maxi=arr[arrSize-1];
    vector<int> leader;
    for(int i=arrSize-1;i>=0;i--){
        if(arr[i]>=maxi){
            maxi=arr[i];
            leader.emplace_back(arr[i]);
        }
    }
    reverse(leader.begin(),leader.end());
    return leader;
}

int main(){
    return 0;
}