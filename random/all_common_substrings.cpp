#include<bits/stdc++.h>
using namespace std;

void f(int i,int j,string& s1,string& s2,vector<string>& answers,string& current_answer){
    if(i==-1 || j==-1){
        if(current_answer.size()>=3){
            reverse(current_answer.begin(),current_answer.end());
            answers.emplace_back(current_answer);
            current_answer.clear();
            return;
        }
        else{
            current_answer.clear();
            return;
        }
    }
    if(s1[i]==s2[j]){
        current_answer+=s1[i];
    }
    else{
        if(current_answer.size()>=3){
            reverse(current_answer.begin(),current_answer.end());
            answers.emplace_back(current_answer);
        }
        current_answer.clear();
    }
    f(i-1,j,s1,s2,answers,current_answer);
    f(i,j-1,s1,s2,answers,current_answer);
}

void all_substrings(string& s1,vector<string>& ans){
    int n=s1.size();
    for(int i=0;i<n-2;i++){
        string current;
        for(int j=2;j<n;j++){
            if(i+j<n){
                current+=s1[i+j];
                ans.emplace_back(current);
            }
            else break;
        }
    }
}

vector<string> all_common_substrings(string& s1,string& s2){ //above length of 3 or equal
    vector<string> answers;
    string current_answer;
    int m=s1.size();
    int n=s2.size();
    f(m-1,n-1,s1,s2,answers,current_answer);
    int n1=answers.size();
    vector<string> ans;
    for(int i=0;i<n1;i++){
        all_substrings(answers[i],ans);
    }
    return ans;
}

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    vector<string> vec=all_common_substrings(s1,s2);
    for(string& s:vec) cout<<s<<" ";
    return 0;
}