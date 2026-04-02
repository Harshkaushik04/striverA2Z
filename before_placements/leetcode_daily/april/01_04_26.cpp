#include<bits/stdc++.h>
using namespace std;

int main(){
    return 0;
}
static bool cons1(pair<pair<int,int>,pair<char,int>> a,pair<pair<int,int>,pair<char,int>> b){
    if(a.first.second<b.first.second) return true;
    if(a.first==b.first){
        if(a.second.first=='L' && b.second.first=='R') return false;
        else if(a.second.first=='R' && b.second.first=='L') return true;
    }
    return false;
}

static bool cons2(pair<int,int> a,pair<int,int> b){
    if(a.second<b.second) return true;
    return false;
}

vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    vector<pair<pair<int,int>,int>> right_direction; //{{health,position},initial index}
    vector<pair<pair<int,int>,int>> left_direction; //{{health,position},initial index}
    int n=positions.size();
    vector<pair<pair<int,int>,pair<char,int>>> vec; //{{health,position},{direction,initial index}}
    for(int i=0;i<n;i++){
        vec.emplace_back(pair<pair<int,int>,pair<char,int>>{pair<int,int>{healths[i],positions[i]},pair<char,int>{directions[i],i}});
    }
    sort(vec.begin(),vec.end(),cons1);
    for(int i=0;i<n;i++){
        pair<pair<int,int>,int> curr=pair<pair<int,int>,int>{pair<int,int>{vec[i].first.first,vec[i].first.second},vec[i].second.second};
        if(vec[i].second.first=='L'){
            int m=right_direction.size();
            bool flag=true;
            for(int j=m-1;j>=0;j--){
                if(right_direction[j].first.first<curr.first.first){
                    right_direction.pop_back();
                    curr.first.first--;
                }
                else if(right_direction[j].first.first==curr.first.first){
                    right_direction.pop_back();
                    flag=false;
                    break;
                }
                else{
                    right_direction[j].first.first--;
                    flag=false;
                    break;
                }
            }
            if(flag) left_direction.emplace_back(curr);
        }
        else if(vec[i].second.first=='R') right_direction.emplace_back(pair<pair<int,int>,int>{{vec[i].first.first,vec[i].first.second},vec[i].second.second});
    }        
    vector<pair<int,int>> combined_direction; //{health,initial index}
    int leftSize=left_direction.size();
    int rightSize=right_direction.size();
    for(int i=0;i<leftSize;i++) combined_direction.emplace_back(pair<int,int>{left_direction[i].first.first,left_direction[i].second});
    for(int i=0;i<rightSize;i++) combined_direction.emplace_back(pair<int,int>{right_direction[i].first.first,right_direction[i].second});
    sort(combined_direction.begin(),combined_direction.end(),cons2);
    int combinedSize=combined_direction.size();
    vector<int> ans;
    for(int i=0;i<combinedSize;i++){
        cout<<combined_direction[i].second<<endl;
        ans.emplace_back(combined_direction[i].first);
    }
    return ans;
}