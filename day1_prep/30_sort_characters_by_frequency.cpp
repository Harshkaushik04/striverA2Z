#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    vector<int> freq(256,0);
    int n=s.size();
    for(int i=0;i<n;i++) freq[s[i]]++;
    vector<pair<int,int>> arr;
    for(int i=0;i<256;i++){
        arr.emplace_back(make_pair(freq[i],i));
    }
    sort(arr.begin(),arr.end(),greater<pair<int,int>>());
    string ans;
    for(int i=0;i<256;i++){
        for(int j=0;j<arr[i].first;j++) ans+=(char) arr[i].second;
    }
    return ans;
}