#include<bits/stdc++.h>
using namespace std;

int kDistinctChar(string& s, int k) {
    //your code goes here
    int l=0,r=0;
    int maxlen=0,len=0;
    unordered_map<char,int> se;
    int n=s.size();
    for(int i=0;i<n;i++){
        r=i;
        if(se.size()<k){
            if(se.find(s[i])!=se.end()) se[s[i]]++;
            else se[s[i]]=1;
            len++;
            maxlen=max(maxlen,len);
            continue;
        }
        if(se.find(s[i])!=se.end()) {
            len++;
            se[s[i]]++;
        }
        else{
            int j=l;
            se[s[r]]=1;
            while(se.size()>k){
                se[s[j]]--;
                if(se[s[j]]==0) se.erase(s[j]);
                j++;
            }
            l=j;
            len=r-l+1;
        }
        maxlen=max(maxlen,len);
    }
    return maxlen;
}