#include<bits/stdc++.h>
using namespace std;

void f(int i,char prev,string& curr,vector<string>& ans_arr,int n){
    if(i==n){
        ans_arr.emplace_back(curr);
        return;
    }
    char alpha='a';
    if(alpha!=prev){
        curr+=alpha;
        f(i+1,alpha,curr,ans_arr,n);
        curr.pop_back();
    }
    alpha='b';
    if(alpha!=prev){
        curr+=alpha;
        f(i+1,alpha,curr,ans_arr,n);
        curr.pop_back();
    }
    alpha='c';
    if(alpha!=prev){
        curr+=alpha;
        f(i+1,alpha,curr,ans_arr,n);
        curr.pop_back();
    }
}

string getHappyString(int n, int k) {
    vector<string> arr;
    string curr;
    f(0,'d',curr,arr,n);
    int ssize=arr.size();
    if(ssize<k) return "";
    return arr[k-1];
}