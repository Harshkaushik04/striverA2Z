#include<bits/stdc++.h>
using namespace std;

int scam_score(int N,int k,vector<int> gift_arr){
    //bs on answers
}

int main(){
    int N,k;
    cin>>N>>k;
    vector<int> gift_arr(k,-1);
    for(int i=0;i<k;i++) cin>>gift_arr[i];
    cout<<scam_score(N,k,gift_arr)<<endl;
    return 0;
}