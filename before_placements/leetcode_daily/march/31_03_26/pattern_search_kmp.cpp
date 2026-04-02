#include<bits/stdc++.h>
using namespace std;

// Function to fill lps[] for given patttern pat[0..M-1].
void computeLPSArray(string pat, int M, int* lps) {
    if(M==0) return;
    lps[0]=0;
    if(M==1) return;
    int prefix_pointer=0;
    int suffix_pointer=1;
    while(suffix_pointer<M){
        if(pat[prefix_pointer]==pat[suffix_pointer]){
            lps[suffix_pointer]=prefix_pointer+1;
            prefix_pointer++;
            suffix_pointer++;
        }
        else{
            while(pat[prefix_pointer]!=pat[suffix_pointer] && prefix_pointer>0){
                prefix_pointer=lps[prefix_pointer-1];
            }
            if(prefix_pointer==0){
                if(pat[prefix_pointer]==pat[suffix_pointer]){
                    lps[suffix_pointer]=prefix_pointer+1;
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
}

// Function to check if the pattern exists in the string or not.
bool KMPSearch(string pat, string txt) {
   int m=pat.size();
   int n=txt.size();
   if(m>n) return false;
   int biggerStringPointer=0; //txt
   int smallerStringPointer=0; //pat
   int* lps=new int[m];
   computeLPSArray(pat,m,lps);
   while(biggerStringPointer<n){
        if(pat[smallerStringPointer]==txt[biggerStringPointer]){
            biggerStringPointer++;
            smallerStringPointer++;
        }
        else{
            while(smallerStringPointer>0 && pat[smallerStringPointer]!=txt[biggerStringPointer]){
                smallerStringPointer=lps[smallerStringPointer-1];
            }
            if(smallerStringPointer==0){
                if(pat[smallerStringPointer]==txt[biggerStringPointer]){
                    smallerStringPointer++;
                    biggerStringPointer++;
                }
                else biggerStringPointer++;
            }
            else{
                smallerStringPointer++;
                biggerStringPointer++;
            }
        }
        if(smallerStringPointer==m) return true; 
   }
   return false;
}