#include<bits/stdc++.h>
using namespace std;

void f(int i1,int i2,string& curr,vector<string>& ans){
        if(i1<0 || i2<0) return;
        if(i1==0 && i2==0){
            ans.emplace_back(curr);
            return;
        }
        if(i1>i2) return;
        if(i1<i2){
            if(i1>0){
                curr.push_back('(');
                f(i1-1,i2,curr,ans);
                curr.pop_back();
            }
            curr.push_back(')');
            f(i1,i2-1,curr,ans);
            curr.pop_back();
        }
        else if(i1==i2){
            curr.push_back('(');
            f(i1-1,i2,curr,ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        f(n,n,curr,ans);
        return ans;
    }