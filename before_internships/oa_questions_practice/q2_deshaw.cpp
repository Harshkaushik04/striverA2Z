#include<bits/stdc++.h>
using namespace std;

vector<int> valid_password_check(vector<string>& passwords){
    int n=passwords.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        stack<char> st;
        for(char ch:passwords[i]){
            if((!st.empty() && ch!=st.top())||st.empty()) st.push(ch);
            else st.pop();
        }
        if(st.empty()) ans.emplace_back(1);
        else ans.emplace_back(0);
    }
    return ans;
}

int main(){
    vector<string> passwords;
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        passwords.emplace_back(s);
    }
    vector<int> ans=valid_password_check(passwords);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}