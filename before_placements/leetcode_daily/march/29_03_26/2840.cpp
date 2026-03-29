#include<bits/stdc++.h>
using namespace std;

bool checkStrings(string s1, string s2) {
    int n=s1.size();
    vector<int> odd_counter(26,0);
    vector<int> even_counter(26,0);
    for(int i=0;i<n;i++){
        if(i%2==0){
            even_counter[s1[i]-'a']++;
            even_counter[s2[i]-'a']--;
        }
        else if(i%2==1){
            odd_counter[s1[i]-'a']++;
            odd_counter[s2[i]-'a']--;
        }
    }
    for(int i:odd_counter){
        if(i!=0) return false;
    }
    for(int i:even_counter){
        if(i!=0) return false;
    }
    return true;
}