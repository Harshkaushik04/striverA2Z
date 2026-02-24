#include<bits/stdc++.h>
using namespace std;

int sumSubarrayMins(vector<int>& arr) {
    int n=arr.size();
    stack<int> st;
    vector<int> psee(n,-1); //previous smaller or equal element
    vector<int> nse(n,n); //next smaller element
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
        if(!st.empty()) psee[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        if(!st.empty()) nse[i]=st.top();
        st.push(i);
    }
    long ans=0;
    long MOD=1000000007;
    for(int i=0;i<n;i++){
        ans+=(long)(i-psee[i])*(nse[i]-i)*arr[i];
        ans%=MOD;
    }
    return ans;
}