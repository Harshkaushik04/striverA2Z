#include<bits/stdc++.h>
using namespace std;

// KMP algo
int getLPSLength(string &s) {
    int n=s.size();
    if(n==0) return 0;
    vector<int> lps(n,0);
    int prefix_pointer=0,suffix_pointer=1;
    lps[0]=0;
    while(suffix_pointer<n){
        if(s[prefix_pointer]==s[suffix_pointer]){
            lps[suffix_pointer]=prefix_pointer+1;
            prefix_pointer++;
            suffix_pointer++;
        }
        else if(s[prefix_pointer]!=s[suffix_pointer]){
            while(prefix_pointer>0 && s[prefix_pointer]!=s[suffix_pointer]){
                prefix_pointer=lps[prefix_pointer-1];
            }
            if(prefix_pointer==0){
                if(s[prefix_pointer]==s[suffix_pointer]){
                    lps[suffix_pointer]=1;
                    prefix_pointer++;
                    suffix_pointer++;
                }
                else{
                    lps[suffix_pointer]=0;
                    suffix_pointer++;
                }
            }
            else{
                lps[suffix_pointer]=prefix_pointer+1;
                prefix_pointer++;
                suffix_pointer++;
            }
        }
    }
    return lps[n-1];
}

int main(){
    return 0;
}