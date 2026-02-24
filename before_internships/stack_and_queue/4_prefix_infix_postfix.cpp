#include<bits/stdc++.h>
using namespace std;

string infixToPostfix(string& s) {
    // code here
    stack<char> st;
    string ans;
    unordered_map<char,int> mpp;
    mpp['^']=3;
    mpp['*']=2;
    mpp['/']=2;
    mpp['+']=1;
    mpp['-']=1;
    for(char ch:s){
        if(ch=='(') st.push(ch);
        else if(ch==')'){
            while(st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        } 
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            if(!st.empty()){
                if(st.top()=='(') st.push(ch);
                else if(mpp[st.top()]<mpp[ch]) st.push(ch);
                else{ //mpp[st.top()]>=mpp[ch]
                    while(!st.empty() && st.top()!='(' && mpp[st.top()]>=mpp[ch]){
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(ch);
                }   
            }
            else st.push(ch);
        }
        else ans+=ch;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

string postToInfix(string s) {
    // Write your code here
    stack<string> st;
    string ans;
    string t1,t2;
    string temp;
    for(char ch:s){
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            temp="("+t2+ch+t1+")";
            st.push(temp);
        }
        else{
            st.push(string(1, ch));
        }
    }
    return st.top();
}

string preToInfix(string s) {
    // Write your code here
    stack<string> st;
    string ans;
    string t1,t2;
    string temp;
    int n=s.size();
    for(int i=n-1;i>=0;i--){
        char ch=s[i];
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            temp="("+t1+ch+t2+")";
            st.push(temp);
        }
        else{
            st.push(string(1, ch));
        }
    }
    return st.top();
}

string postToPre(string s) {
    // Write your code here
    stack<string> st;
    string ans;
    string t1,t2;
    string temp;
    for(char ch:s){
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            temp=ch+t2+t1;
            st.push(temp);
        }
        else{
            st.push(string(1, ch));
        }
    }
    return st.top();
}

string preToPost(string s) {
    // Write your code here
    stack<string> st;
    string ans;
    string t1,t2;
    string temp;
    int n=s.size();
    for(int i=n-1;i>=0;i--){
        char ch=s[i];
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            temp=t1+t2+ch;
            st.push(temp);
        }
        else{
            st.push(string(1, ch));
        }
    }
    return st.top();
}


string InfixToPre(string s) {
    // Write your code here
    stack<char> st;
    string ans;
    reverse(s.begin(),s.end());
    unordered_map<char,int> mpp;
    mpp['^']=3;
    mpp['*']=2;
    mpp['/']=2;
    mpp['+']=1;
    mpp['-']=1;
    for(char ch:s){
        if(ch==')') st.push(ch);
        else if(ch=='('){
            while(st.top()!=')'){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        } 
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            if(!st.empty()){
                if(st.top()==')') st.push(ch);
                else if(mpp[st.top()]<=mpp[ch]) st.push(ch);
                else{ //mpp[st.top()]>=mpp[ch]
                    while(!st.empty() && st.top()!=')' && mpp[st.top()]>mpp[ch]){
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(ch);
                }   
            }
            else st.push(ch);
        }
        else if(ch=='^'){
            if(st.top()==')') st.push(ch);
            else if(st.top()=='^'){
                while(!st.empty() && st.top()!=')' && st.top()=='^'){
                    ans+=st.top();
                    st.pop();
                }
                st.push(ch);
            }
            else st.push(ch);
        }
        else ans+=ch;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s,ans;
    cin>>s;
    ans=InfixToPre(s);
    cout<<ans<<endl;
    return 0;
}   