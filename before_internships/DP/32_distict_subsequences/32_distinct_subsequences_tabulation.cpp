#include<bits/stdc++.h>
using namespace std;

int numDistinct(string s, string t){
    int size1=s.size();
    int size2=t.size();
    vector<double> current(size2+1,0);
    current[0]=1;
    for(int i=0;i<size1;i++){
        for(int j=size2;j>0;j--){
            if(s[i]==t[j-1]){
                current[j]=current[j-1]+current[j];
            }
        }
    }
    return current[size2];
} 