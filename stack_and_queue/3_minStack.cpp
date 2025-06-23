#include<bits/stdc++.h>
using namespace std;

class MinStack {
    public:
        int mini;
        stack<int> st;
        void push(int val) {
            if(st.empty()){
                st.push(val);
                mini=val;
            }
            else{
                if(mini>val){
                    st.push(2*val-mini);
                    mini=val;
                }
                else{
                    st.push(val);
                }
            }
        }
        void pop(){
            int m=st.top();
            if(m<mini){
                mini=2*mini-m;
                st.pop();
            }
            else st.pop();
        }
        int top() {
            int m=st.top();
            if(m<mini) return mini;
            else return m;
        }
        int getMin() {
            return mini;
        }
    };