#include<bits/stdc++.h>
using namespace std;
//not done
bool parseBoolExpr(string expression) {
    stack<char> st;
    stack<char> operators;
    int i=0;
    int n=expression.size();
    unordered_map<char,bool> mpp;
    unordered_map<bool,char> mpp1;
    mpp['f']=false;
    mpp['t']=true;
    mpp1[false]='f';
    mpp1[true]='t';
    for(int i=0;i<n;i++){
        char ch=expression[i];
        if(ch=='f' || ch=='t') st.push(ch);
        else{
            if(ch=='(' || ch=='&' || ch=='|' || ch=='!') operators.push(ch);
            else if(ch=')'){
                while(!operators.empty() && operators.top()=='(' && ch==')'){
                    operators.pop();
                    i++;
                    ch=expression[i];
                }
                if(operators.empty()) break;
                if(operators.top()=='!') st.top()=mpp1[!mpp[st.top()]];
                else if(operators.top()=='&'){
                    bool ans=true;
                    while(!st.empty() && (st.top()=='f' || st.top()=='t')){
                        ans&=mpp[st.top()];
                        st.pop();
                    }
                    st.push(mpp1[ans]);
                }
                else if(operators.top()=='&'){
                    bool ans=false;
                    while(!st.empty() && (st.top()=='f' || st.top()=='t')){
                        ans|=mpp[st.top()];
                        st.pop();
                    }
                    st.push(mpp1[ans]);
                }
            }
        }
    }
    return mpp1[st.top()];
}