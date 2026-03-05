#include<bits/stdc++.h>
using namespace std;

void print_vectorPairPairIntIntString(vector<pair<pair<int,int>,string>>& v){
    for(const pair<pair<int,int>,string>& p:v){
        cout<<"{"<<p.first.first<<","<<p.first.second<<"},"<<p.second<<"\n";
    }
}

void print_vectorPairIntString(vector<pair<int,string>>& v){
    for(const pair<int,string>& p:v){
        cout<<"{"<<p.first<<","<<p.second<<"}"<<"\n";
    }
}

void print_mapIntInt(map<int,int,greater<int>>& mpp){
    for(const pair<int,int>& p:mpp){
        cout<<"{"<<p.first<<","<<p.second<<"}"<<"\n";
    }
}

bool comp(const pair<int,int>& a,const pair<int,int>& b){
    if(a.first<b.first) return true;
    else if(a.first>b.first) return false;
    else{
        if(a.second==1) return true;
        else return false;
    }
}

vector<pair<pair<int,int>,int>> lineSweep_events(vector<pair<int,int>>& queries){ // index,times,start
    vector<pair<int,int>> lse;
    for(pair<int,int>& p:queries){
        lse.emplace_back(pair<int,int>{p.first,1});
        lse.emplace_back(pair<int,int>{p.second,-1});
    }
    sort(lse.begin(),lse.end(),comp);
    int n=lse.size();
    pair<int,int> curr={0,2};
    int i=0;
    int streak=1;
    vector<pair<pair<int,int>,int>> actual_lse;
    while(i<n){
        if(curr.first==lse[i].first && curr.second==lse[i].second) streak++;
        else{
            if(curr.second!=2){
                actual_lse.emplace_back(pair<pair<int,int>,int>{pair<int,int>{curr.first,streak},curr.second});
                streak=1;
            }
        }
        curr=lse[i];
        i++;
    }
    actual_lse.emplace_back(pair<pair<int,int>,int>{pair<int,int>{curr.first,streak},curr.second});
    return actual_lse;
}

using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    vector<int> arr;
    vector<pair<int,int>> queries;
    cin>>n>>q;
    int temp1;
    int temp2;
    for(int i=0;i<n;i++){
        cin>>temp1;
        arr.emplace_back(temp1);
    }
    for(int i=0;i<q;i++){
        cin>>temp1>>temp2;
        queries.emplace_back(pair<int,int>{temp1,temp2});
    }
    vector<pair<pair<int,int>,int>> actual_lse = lineSweep_events(queries); // {{index,num_events_at_that_index},"start/end"}
    int m=actual_lse.size();
    int temp=0;
    int prev=-1;
    unordered_map<int,int> multiplyFactor_to_numIndexes;
    int prev_event=2;
    for(int i=0;i<m;i++){
        pair<int,int> p=actual_lse[i].first;
        int event=actual_lse[i].second;
        if(event==1){
            if(prev_event==1){
                if(multiplyFactor_to_numIndexes.find(temp)!=multiplyFactor_to_numIndexes.end()) multiplyFactor_to_numIndexes[temp]+=(p.first-prev);
                else multiplyFactor_to_numIndexes[temp]=p.first-prev;
            }
            else if(prev_event==-1){
                if(multiplyFactor_to_numIndexes.find(temp)!=multiplyFactor_to_numIndexes.end()) multiplyFactor_to_numIndexes[temp]+=(p.first-prev-1);
                else multiplyFactor_to_numIndexes[temp]=p.first-prev-1;
            }
            temp+=p.second;
        }
        else if(event==-1){
            if(prev_event==1){
                if(multiplyFactor_to_numIndexes.find(temp)!=multiplyFactor_to_numIndexes.end()) multiplyFactor_to_numIndexes[temp]+=(p.first-prev+1);
                else multiplyFactor_to_numIndexes[temp]=p.first-prev+1;
            }
            else if(prev_event==-1){
                if(multiplyFactor_to_numIndexes.find(temp)!=multiplyFactor_to_numIndexes.end()) multiplyFactor_to_numIndexes[temp]+=(p.first-prev);
                else multiplyFactor_to_numIndexes[temp]=p.first-prev;
            }
            temp-=p.second;
        }
        prev_event=event;
        prev=p.first;
    }
    sort(arr.begin(),arr.end(),greater<int>());
    ll ans=0;
    int index=0;
    map<int,int,greater<int>> mpp(multiplyFactor_to_numIndexes.begin(),multiplyFactor_to_numIndexes.end());
    for(const pair<int,int>& p:mpp){
        int num_indexes=p.second;
        for(int i=0;i<num_indexes;i++){
            ans+=(ll) p.first*arr[index];
            index++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}




/*
C. Little Girl and Maximum Sum
time limit per test
1 second
memory limit per test
256 megabytes

The little girl loves the problems on array queries very much.

One day she came across a rather well-known problem: you've got an array of n elements (the elements of the array are indexed starting from 1); also, there are q queries, each one is defined by a pair of integers li, ri (1≤li≤ri≤n). You need to find for each query the sum of elements of the array with indexes from li to ri, inclusive.

The little girl found the problem rather boring. She decided to reorder the array elements before replying to the queries in a way that makes the sum of query replies maximum possible. Your task is to find the value of this maximum sum.
Input

The first line contains two space-separated integers n (1≤n≤2⋅105) and q (1≤q≤2⋅105) — the number of elements in the array and the number of queries, correspondingly.

The next line contains n space-separated integers ai (1≤ai≤2⋅105) — the array elements.

Each of the following q lines contains two space-separated integers li and ri (1≤li≤ri≤n) — the i-th query.
Output

In a single line print, a single integer — the maximum sum of query replies after the array elements are reordered.

Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specifier.
*/