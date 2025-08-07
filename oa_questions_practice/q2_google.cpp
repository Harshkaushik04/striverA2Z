#include<bits/stdc++.h>
using namespace std;

vector<int> swaps(int n,vector<int> arr,vector<vector<int>> queries,int q){
    int num_ones=0,num_twos=0,num_threes=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1) num_ones++;
        else if(arr[i]==2) num_twos++;
        else num_threes++;
    }
    int twos_start=num_ones,threes_start=num_ones+num_twos;
    unordered_map<int,int> ones_in_twos;
    unordered_map<int,int> ones_in_threes;
    unordered_map<int,int> twos_in_ones;
    unordered_map<int,int> twos_in_threes;
    unordered_map<int,int> threes_in_ones;
    unordered_map<int,int> threes_in_twos;
    for(int i=0;i<n;i++){
        if(i<twos_start){
            if(arr[i]==2) twos_in_ones[i]=1;
            else if(arr[i]==3) threes_in_ones[i]=1;
        }
        else if(i>=twos_start && i<threes_start){
            if(arr[i]==1) ones_in_twos[i]=1;
            else if(arr[i]==3) threes_in_twos[i]=1;
        }
        else if(i>=threes_start){
            if(arr[i]==1) ones_in_threes[i]=1;
            else if(arr[i]==2) twos_in_threes[i]=1;
        }
    }
    vector<int> ans;
    for(vector<int>& query:queries){
        int temp=arr[query[0]];
        arr[query[0]]=query[1];
        vector<int> data={query[0],temp,query[1]};; //index,prev,current
        if(temp==1){
            if(query[1]==2){
                num_twos++;
                num_ones--;
            }
            else if(query[1]==3){
                num_threes++;
                num_ones--;
            }
        }
        else if(temp==2){
            if(query[1]==1){
                num_twos--;
                num_ones++;
            }
            else if(query[1]==3){
                num_threes++;
                num_twos--;
            }
        }
        else if(temp==3){
            if(query[1]==2){
                num_twos++;
                num_threes--;
            }
            else if(query[1]==1){
                num_threes--;
                num_ones++;
            }
        }
        twos_start=num_ones;
        threes_start=num_ones+num_twos;
        for(int i=query[0]-1;i<=query[0]+1;i++){
            if(i>=0 && i<n){
                if(temp==1){
                    if(ones_in_twos.find(i)!=ones_in_twos.end()) ones_in_twos.erase(i);
                    else if(ones_in_threes.find(i)!=ones_in_threes.end()) ones_in_threes.erase(i);
                }
                else if(temp==2){
                    if(twos_in_ones.find(i)!=twos_in_ones.end()) twos_in_ones.erase(i);
                    else if(twos_in_threes.find(i)!=twos_in_threes.end()) twos_in_threes.erase(i);
                }
                else if(temp==3){
                    if(threes_in_ones.find(i)!=threes_in_ones.end()) threes_in_ones.erase(i);
                    else if(threes_in_twos.find(i)!=threes_in_ones.end()) threes_in_twos.erase(i);
                }
                if(query[1]==1){
                    if(i>=twos_start && i<threes_start) ones_in_twos[i]=1;
                    else if(i>=threes_start) ones_in_threes[i]=1;
                }
                else if(query[1]==2){
                    if(i<twos_start) twos_in_ones[i]=1;
                    else if(i>=threes_start) twos_in_threes[i]=1;
                }
                else if(query[1]==3){
                    if(i<twos_start) threes_in_ones[i]=1;
                    else if(i>=twos_start && i<threes_start) threes_in_twos[i]=1;
                }
            }
        }
        int num_swaps=(ones_in_twos.size()+ones_in_threes.size()+twos_in_ones.size()+twos_in_threes.size()
            +threes_in_ones.size()+threes_in_twos.size())/2;
        ans.emplace_back(num_swaps);
    }
    return ans;
}

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr(n,-1);
    vector<vector<int>> queries(q,vector<int>(2,-1));
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<q;i++){
        cin>>queries[i][0]>>queries[i][1];
    }
    vector<int> ans=swaps(n,arr,queries,q);
    for(int i=0;i<q;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
