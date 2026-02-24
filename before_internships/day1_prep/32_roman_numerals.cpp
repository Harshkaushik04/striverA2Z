#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
     string curr;
     int i=0;
     int n=s.size();
     int ans=0;
     while(i<n){
        // cout<<"curr:"<<curr<<endl;
        // cout<<"ans:"<<ans<<endl;
        if(s[i]=='I'){
            int num=0;
            while(i<n && s[i]=='I'){
                num++;
                i++;
            }
            if(i==n){
                ans+=num;
                return ans;
            }
            else if(num==1){
                if(s[i]=='V'){
                    ans+=4;
                    i++;
                }
                else if(s[i]=='X'){
                    ans+=9;
                    i++;
                }
            }
            else ans+=num;
        }
        else if(s[i]=='V'){
            if(curr=="I"){
                ans+=4;
                i++;
                curr.clear();
            }
            else{
                ans+=5;
                i++;
            }
        }
        else if(s[i]=='X'){
            if(curr=="I"){
                ans+=9;
                i++;
                curr.clear();
            }
            else{
                if(i==n-1){
                    ans+=10;
                    i++;
                }
                else{
                    if(s[i+1]=='C'){
                        ans+=90;
                        i+=2;
                    }
                    else if(s[i+1]=='L'){
                        ans+=40;
                        i+=2;
                    }
                    else{
                        ans+=10;
                        i++;
                    }
                }
            }
        }
        else if(s[i]=='C'){
            if(i==n-1){
                ans+=100;
                i++;
            }
            else{
                if(s[i+1]=='D'){
                    ans+=400;
                    i+=2;
                }
                else if(s[i+1]=='M'){
                    ans+=900;
                    i+=2;
                }
                else{
                    ans+=100;
                    i++;
                }
            }
        }
        else if(s[i]=='M'){
            ans+=1000;
            i++;
        }
        else if(s[i]=='D'){
            ans+=500;
            i++;
        }
        else if(s[i]=='L'){
            ans+=50;
            i++;
        }
     }
    //  cout<<"last_curr:"<<curr<<endl;
     return ans;
}