#include<bits/stdc++.h>
using namespace std;

// bool isAnagram(string s, string t) {
//     if(s.size()!=t.size()) return false;
//     int n=s.size();
//     unordered_map<char,int> mpp;
//     for(int i=0;i<n;i++){
//         if(mpp.find(s[i])==mpp.end()) mpp[s[i]]=1;
//         else mpp[s[i]]++;
//         if(mpp.find(t[i])==mpp.end()) mpp[t[i]]=-1;
//         else mpp[t[i]]--;
//     }
//     for(auto& p:mpp){
//         if(p.second!=0) return false;
//     }
//     return true;
// }

  bool isAnagram(string s, string t){
    if(s.size()!=t.size()) return false;
    int n=s.size();
    vector<int> vec(256,0);
    for(int i=0;i<n;i++){
        vec[s[i]]++;
        vec[t[i]]--;
    }
    for(int p:vec){
        if(p!=0) return false;
    }
    return true;
}