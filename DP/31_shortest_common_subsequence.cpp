#include<bits/stdc++.h>
using namespace std;
//not done

string lcs_val(string s1,string s2){
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
    return last[size2-1];
}


string shortestCommonSupersequence(string str1, string str2) {
    string lcs=lcs_val(str1,str2);
    int n=lcs.size();
    int size1=str1.size();
    int size2=str2.size();
    if(n==0) return str1+str2;
    string temp1="",temp3=""; //for str1
    string temp4="",temp6=""; //for str2
    string combinedTemp=""; //middle
    char target;
    bool flag1=false,flag2=false;
    int p1,p2;
    for(int i=0;i<size1;i++){
        target=lcs[0];
        if(!flag1){
            if(str1[i]!=target) temp1+=str1[i];
            else{
                flag1=true;
                p1=i;
                break;
            }
        }
    }
    flag1=false,flag2=false;
    for(int i=0;i<size2;i++){
        target=lcs[0];
        if(!flag1){
            if(str2[i]!=target) temp4+=str2[i];
            else{
                p2=i;
                flag1=true;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        target=lcs[i];
        flag1=false,flag2=false;
        while(!flag1 && !flag2){
            if(!flag1){
                if(target==str1[p1]) {
                    flag1=true;
                    if(!flag2) combinedTemp+=str1[p1];
                }
                else combinedTemp+=str1[p1];
                p1++;
            }
            if(!flag2){
                if(target==str2[p2]) {
                    flag2=true;
                    if(!flag1) combinedTemp+=str2[p2];
                }
                else combinedTemp+=str2[p2];
                p2++;
            }
        }
    }
    if(p1<size1){
        temp3=str1.substr(p1,size1);
    }
    if(p2<size2){
        temp6=str2.substr(p2,size2);
    }
    cout<<"temp1:"<<temp1<<endl;
    cout<<"temp4:"<<temp4<<endl;
    cout<<"combinedTemp:"<<combinedTemp<<endl;
    cout<<"temp3:"<<temp3<<endl;
    cout<<"temp6:"<<temp6<<endl;
    cout<<"lcs:"<<lcs<<endl;
    return temp1+temp4+combinedTemp+temp3+temp6;
}

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    string ans=shortestCommonSupersequence(s1,s2);
    cout<<ans<<endl;
    return 0;
}