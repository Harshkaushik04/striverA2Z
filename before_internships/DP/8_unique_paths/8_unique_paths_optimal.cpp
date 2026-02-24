#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    vector<int> next(n,-1);
    vector<int> current(n,-1);
    current[0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j+1<n){
                if(current[j+1]!=-1) current[j+1]+=current[j];
                else current[j+1]=current[j];
            }
            if(i+1<m) next[j]=current[j];
        }
        if(i!=m-1) current=next;
    }
    return current[n-1];
}
