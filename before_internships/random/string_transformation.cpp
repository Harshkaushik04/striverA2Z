#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        unordered_map<char,int> mpp;
        vector<int> vec1,vec2;
        cin>>s1;
        cin>>s2;
        for(char ch:s1){
            if(mpp.begin(ch)!=mpp.end()) mpp[ch]++;
            else mpp[ch]=1;
        }
        for(auto& p:mpp) vec1.emplace_back(p.second);
        mpp.clear();
        for(char ch:s2){
            if(mpp.begin(ch)!=mpp.end()) mpp[ch]++;
            else mpp[ch]=1;
        }
        for(auto& p:mpp) vec2.emplace_back(p.second);
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());
        if(vec1==vec2) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
    return 0;
}