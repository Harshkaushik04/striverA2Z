#include<bits/stdc++.h>
using namespace std;

// bool isIsomorphic(string s, string t) {
//     int n=s.size();
//     unordered_map<char,char> mpp,mpp1;
//     for(int i=0;i<n;i++){
//         if(mpp.find(s[i])==mpp.end()){
//             if(mpp1.find(t[i])==mpp1.end()){
//                 mpp[s[i]]=t[i];
//                 mpp1[t[i]]=s[i];
//             }
//             else return false;
//         }
//         else{
//             if(mpp1.find(t[i])==mpp1.end()) return false;
//             else{
//                 if(mpp1.find(t[i])==mpp1.end()) return false;
//                 else if(mpp1[t[i]]==s[i]) continue;
//                 else return false;
//             }
//         }
//     }
//     return true;
// }

bool isIsomorphic(string s, string t) {
    int n=s.size();
    vector<int> vec(26,-1),vec1(26,-1);
    for(int i=0;i<n;i++){
        int curr1=s[i]-'a';
        int curr2=t[i]-'a';
        if(vec[curr1]==-1){
            if(vec1[curr2]==-1){
                vec[curr1]=curr2;
                vec[curr2]=curr1;
            }
            else return false;
        }
        else{
            if(vec[curr2]==-1 || vec[curr2]!=curr1) return false;
        }
    }
    return true;
}