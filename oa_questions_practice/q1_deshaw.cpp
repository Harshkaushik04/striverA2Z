#include<bits/stdc++.h>
using namespace std;

int num_switch(vector<int>& transactions){
    int n=transactions.size();
    if(n==1) return abs(transactions[0]);
    int ans=0;
    int next=transactions[n-1];
    for(int i=n-2;i>=0;i--){
        if(transactions[i]>next){
            int temp=transactions[i]-next;
            for(int j=0;j<=i;j++){
                transactions[j]-=temp;
                ans+=temp;
            }
        }
        else if(transactions[i]<next){
            int temp=next-transactions[i];
            for(int j=0;j<=i;j++){
                transactions[j]+=temp;
                ans+=temp;
            }
        }
        next=transactions[i];
    }
    return ans;
}

int main(){
    vector<int> transactions;
    int n,temp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        transactions.emplace_back(temp);
    }
    cout<<num_switch(transactions)<<endl;
    return 0;
}