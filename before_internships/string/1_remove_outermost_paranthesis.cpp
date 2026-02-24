#include<bits/stdc++.h>
using namespace std;
//not done
string removeOuterParentheses(string s) {
    int counter=0;
    vector<int> endIndexes={-1};
    int size=s.size();
    int i=0;
    for(char ch:s){
        if(ch=='(') counter++;
        else counter--;
        if(counter==0) endIndexes.emplace_back(i);
        i++;
    }
    int n=endIndexes.size();
    counter=0;
    string temp;
    int t;
    string ans;
    for(int i=0;i<n;i++){
        if(i<n-1) temp=s.substr(endIndexes[i]+1,endIndexes[i+1]+1);
        else{
        if(endIndexes[i]+1<size) temp=s.substr(endIndexes[i]+1,size);
        else temp="";
        }
        t=temp.size();
        counter=0;
        i=0;
        while(t--){
            if(temp[i]=='(') counter++;
            else break;
        }
        t=temp.size();
        temp=temp.substr(counter-1,t-counter+1);
        ans+=temp;
    }
    return ans;
}
