#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s){
    stack<char> st;
    string ans;
    for(char ch:s){
        if(ch=='(' && !st.empty()) ans+=ch;
        else if(ch==')' && !(st.size()==1 && st.top()=='(')) ans+=ch;
        if(st.empty() || st.top()==ch) st.push(ch);
        else st.pop();
    }
    return ans;
}