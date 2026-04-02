#include<bits/stdc++.h>
using namespace std;

//str1->"TFTF"
//str2->"abab"

string generateString(string str1, string str2) {
    int n=str1.size();
    int m=str2.size();
    string ans(m+n-1,' ');
    vector<bool> changable(m+n-1,true);
    for(int i=0;i<n;i++){
        if(str1[i]=='F') continue;
        for(int j=0;j<m;j++){
            if(ans[i+j]!=' ' && ans[i+j]!=str2[j]) return "";
            else{
                ans[i+j]=str2[j];
                changable[i+j]=false;
            }
        }
    }
    for(int i=0;i<m+n-1;i++){
        if(ans[i]==' ') ans[i]='a';
    }
    for(int i=0;i<n;i++){
        if(str1[i]=='T') continue;
        bool flag=false;
        for(int j=0;j<m;j++){
            if(ans[i+j]!=str2[j]){
                flag=true;
                break;
            }
        }
        if(!flag){ //procedure of conversion
            bool flag1=false;
            int k=i+m-1;
            while(k>=i){
                if(ans[k]!='z' && changable[k]){
                    ans[k]++;
                    flag1=true;
                    break;
                }
                else if(!changable[k]) k--;
                else{ // ans[k]=='z' && changable[k]
                    ans[k]='a';
                    k--;
                    while(k>=i && ans[k]=='z'){
                        ans[k]='a';
                        k--;
                    }
                }
            }
            if(!flag1) return "";
        }
    }
    return ans;
}

int main(){
    return 0;
}

