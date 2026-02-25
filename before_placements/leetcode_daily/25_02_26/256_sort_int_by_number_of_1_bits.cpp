#include<bits/stdc++.h>
using namespace std;

void numOnes(int n,int& ans){
    if(n==0) return;
    int m=log2(n);
    n-=pow(2,m);
    ans++;
    numOnes(n,ans);
}


vector<int> sortByBits(vector<int>& arr) {
    vector<pair<int,int>> actual_arr;
    int length=size(arr);
    for(int i=0;i<length;i++){
        int ans=0;
        numOnes(arr[i],ans);
        actual_arr.emplace_back(pair<int,int>{ans,arr[i]});
    }
    sort(actual_arr.begin(),actual_arr.end());
    vector<int> answer;
    for(int i=0;i<length;i++){
        answer.emplace_back(actual_arr[i].second);
    }
    return answer;
}

int main(){
    return 0;
}