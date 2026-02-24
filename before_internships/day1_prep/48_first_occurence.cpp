#include<bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle) {
        int i=0;
        int j=0;
        int n=haystack.size();
        int m=needle.size();
        int start=-1;
        while(i<n && j<m){
            if(haystack[i]==needle[j]){
                if(j==0) start=i;
                i++;
                j++;
            } 
            else{     
                if(j==0){
                    i++;
                    continue;
                }
                i=start+1;
                j=0;
                if(needle[j]==haystack[i]){
                    start=i;
                    i++;
                    j++;
                }
                else i++;
            }
        }
        if(j==m) return start;
        else return -1;
    }