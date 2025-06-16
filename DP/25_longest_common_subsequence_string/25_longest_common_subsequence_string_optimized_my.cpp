#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int size1=text1.size();
    int size2=text2.size();
    int temp;
    vector<int> current(size2,0);
    vector<int> last(size2,0);
    temp=size2-1;
    for(int i=0;i<size2;i++){
        if(text1[0]==text2[i]){
            last[i]=1;
            temp=i;
            break;
        }
    }
    for(int i=temp+1;i<size2;i++){
        last[i]=1;
    }
    bool flag=false;
    if(text1[0]==text2[0]) flag=true;
    for(int i=1;i<size1;i++){
        if(!flag && text1[i]==text2[0]){
            flag=true;
        }
        if(flag) current[0]=1;
        else current[0]=0;
        for(int j=1;j<size2;j++){
            if(text1[i]==text2[j]) current[j]=1+last[j-1];
            else current[j]=max(last[j],current[j-1]);
        }
        last=current;
    }
    return last[size2-1];
}