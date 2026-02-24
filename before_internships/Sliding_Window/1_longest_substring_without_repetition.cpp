#include<bits/stdc++.h>
using namespace std;

//using map
// int lengthOfLongestSubstring(string s){
//     int l=0,r=-1;
//     int maxlen=0;
//     map<char,int> mpp;
//     int n=s.size();
//     map<char,int>::iterator temp;
//     int len=0;
//     for(int i=0;i<n;i++){
//         r=i;
//         temp=mpp.find(s[r]);
//         if(temp==mpp.end()||mpp[s[r]]<l){
//             len++;
//             mpp[s[r]]=r;
//         }
//         else{
//             l=mpp[s[r]]+1;
//             mpp[s[r]]=r;
//             len=r-l+1;
//         }
//         maxlen=max(maxlen,len);
//     }
//     return maxlen;
// }

int lengthOfLongestSubstring(string s){
    int l=0,r=-1;
    int maxlen=0;
    vector<int> mpp(256,-1); //ASCII MAP
    int n=s.size();
    map<char,int>::iterator temp;
    int len=0;
    for(int i=0;i<n;i++){
        r=i;
        if(mpp[s[r]]==-1||mpp[s[r]]<l){
            len++;
            mpp[s[r]]=r;
        }
        else{
            l=mpp[s[r]]+1;
            mpp[s[r]]=r;
            len=r-l+1;
        }
        maxlen=max(maxlen,len);
    }
    return maxlen;
}