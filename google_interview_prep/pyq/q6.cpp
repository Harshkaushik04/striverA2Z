#include<bits/stdc++.h>
using namespace std;

/*
Question - Given a list of all the words in an English dictionary, find all the combinations of five lettered words that use up 25 distinct letters.
*/

/*
arguments would be wordDict: vector<string>
since we will comparing each word with another to find if they both have distinct letters so using bitmask would be 
effecient(also the number of possible letters is 26(limited:in range of int))
=>can represent every string as a 26 bit int
for example "harsh" can be represented by 
00000001100000000010000001
we can make a function which stores current index(of wordDict) and also a single 26 bit int which represents all the
letters which we have chosen till now, we can also keep a counter for number of words we have chosen till now
if that counter reaches 5 then increase ans by 1 
we can make a helper recursive function

f(wordDict,index_of_wordDict,counter,ans,bitmask_store){
    if wordDict[index]&bitmask_store==0 => pick/not pick
    if counter reached 5=>ans++ then return
    else wordDict[index]& bitmask_store!=0 =>not pick
}
*/
//make a function to decrease the search space of wordDict by removing letters with repeating letters
vector<string> decrease_search_space(vector<string>& wordDict){
    vector<string> newWordDict;
    for(string& word:wordDict){
        bool break_flag=false;
        int bitmask=0;
        for(char ch:word){
            if(bitmask & (1<<(ch-'a'))){
                break_flag=true;
                break;
            }
            else bitmask|=(1<<(ch-'a'));
        }
        if(!break_flag) newWordDict.emplace_back(word);
    }
    return newWordDict;
}

//function to convert string to bitmask
int str_to_bitmask(string& s){
    int bitmask=0;
    for(char ch:s){
        bitmask=bitmask|(1<<(ch-'a'));
    }
    return bitmask;
}

void helperFunc(vector<string>& wordDict,int ssize,int bitmask,int index,int counter,int& ans){
    //base case 
    if(counter>=5){
        ans++;
        return;
    }
    if(index>=ssize) return;
    int bitmasked_string=str_to_bitmask(wordDict[index]);
    if((bitmask & bitmasked_string)==0){
        int modified_bitmask=bitmask|bitmasked_string;
        //take
        helperFunc(wordDict,ssize,modified_bitmask,index+1,counter+1,ans);
        //not_take
        helperFunc(wordDict,ssize,bitmask,index+1,counter,ans);
    }
    else{
        //only not_take is possible
        helperFunc(wordDict,ssize,bitmask,index+1,counter,ans);
    }
}
//assuming wordDict is only made up of 5 lettered words
int find_combinatations(vector<string>& wordDict){
    int bitmask=0;
    int ans=0;
    vector<string> newWordDict=decrease_search_space(wordDict);
    int ssize=newWordDict.size();
    helperFunc(newWordDict,ssize,bitmask,0,0,ans);
    return ans;
}