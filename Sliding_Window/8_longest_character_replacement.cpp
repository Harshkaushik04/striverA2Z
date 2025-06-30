#include<bits/stdc++.h>
using namespace std;

//unordered_map
// int characterReplacement(string s, int k) {
//     unordered_map<char,int> mpp;
//     int l=0,r=0;
//     int max_freq=0;
//     int n=s.size();
//     int maxlen=0;
//     for(int i=0;i<n;i++){
//         r=i;
//         if(mpp.find(s[i])==mpp.end()) mpp[s[i]]=1;
//         else mpp[s[i]]++;
//         max_freq=max(max_freq,mpp[s[i]]);
//         while(r-l+1-max_freq>k){
//             mpp[s[l]]--;
//             l++;
//             max_freq=0;
//             for(pair<const char,int>& p:mpp) max_freq=max(max_freq,p.second);
//         }
//         maxlen=max(maxlen,r-l+1);
//     }
//     return maxlen;
// }

//vector<int>
int characterReplacement(string s, int k) {
    vector<int> mpp(26,0);
    int l=0,r=0;
    int max_freq=0;
    int n=s.size();
    int maxlen=0;
    for(int i=0;i<n;i++){
        r=i;
        mpp[s[i]-'A']++;
        max_freq=max(max_freq,mpp[s[i]-'A']);
        while(r-l+1-max_freq>k){
            mpp[s[l]-'A']--;
            l++;
            max_freq=0;
            for(int j=0;j<26;j++) max_freq=max(max_freq,mpp[j]);
        }
        maxlen=max(maxlen,r-l+1);
    }
    return maxlen;
}