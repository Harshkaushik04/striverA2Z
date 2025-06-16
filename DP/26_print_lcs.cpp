#include<bits/stdc++.h>
using namespace std;

void print_lcs(string s1,string s2){
    int size1=s1.size(),size2=s2.size();
    vector<string> current(size2,"");
    vector<string> last(size2,"");
    int temp;
    for(int i=0;i<size2;i++){
        if(s1[0]==s2[i]){
            last[i]=s1[0];
            temp=i;
            break;
        }
    }
    for(int i=temp+1;i<size2;i++){
        last[i]=s1[0];
    }
    bool flag=false;
    if(s1[0]==s2[0]) flag=true;
    for(int i=1;i<size1;i++){
        if(!flag && s1[i]==s2[0]) flag=true;
        if(flag) current[0]=s2[0];
        else current[0]="";
        for(int j=1;j<size2;j++){
            if(s1[i]==s2[j]) current[j]=last[j-1]+s1[i];
            else{
                if(last[j].size()>=current[j-1].size()) current[j]=last[j];
                else current[j]=current[j-1];
            }
        }
        last=current;
    }
    cout<<last[size2-1]<<endl;
}

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    print_lcs(s1,s2);
    return 0;
}