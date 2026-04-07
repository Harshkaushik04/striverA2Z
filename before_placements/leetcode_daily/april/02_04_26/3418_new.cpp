#include<bits/stdc++.h>
using namespace std;

int maximumAmount(vector<vector<int>>& coins) {
    int m=coins.size();
    int n=coins[0].size();
    vector<vector<int>> curr(n,vector<int>(3,0));
    vector<vector<int>> prev(n,vector<int>(3,0));
    if(coins[m-1][n-1]<0){
        curr[n-1][0]=coins[m-1][n-1];
        curr[n-1][1]=0;
        curr[n-1][2]=0;
    }
    else{
        curr[n-1][0]=coins[m-1][n-1];
        curr[n-1][1]=coins[m-1][n-1];
        curr[n-1][2]=coins[m-1][n-1];
    }
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            for(int ability=0;ability<3;ability++){
                if(i==m-1 && j==n-1) continue;
                else if(i==m-1){
                    int ability_not_use=coins[i][j]+curr[j+1][ability];
                    if(coins[i][j]<0){
                        if(ability>0){
                            int ability_use=curr[j+1][ability-1];
                            curr[j][ability]=max(ability_use,ability_not_use);
                        }
                        else curr[j][ability]=ability_not_use;
                    }
                    else curr[j][ability]=ability_not_use;
                }
                else if(j==n-1){
                    int ability_not_use=coins[i][j]+prev[j][ability];
                    if(coins[i][j]<0){
                        if(ability>0){
                            int ability_use=prev[j][ability-1];
                            curr[j][ability]=max(ability_use,ability_not_use);
                        }
                        else curr[j][ability]=ability_not_use;
                    }
                    else curr[j][ability]=ability_not_use;
                }
                else{
                    int ability_not_use_down=coins[i][j]+prev[j][ability];
                    int ability_not_use_right=coins[i][j]+curr[j+1][ability];
                    int ability_not_use=max(ability_not_use_down,ability_not_use_right);
                    if(coins[i][j]<0){
                        if(ability>0){
                            int ability_use_down=prev[j][ability-1];
                            int ability_use_right=curr[j+1][ability-1];
                            int ability_use=max(ability_use_down,ability_use_right);
                            curr[j][ability]=max(ability_not_use,ability_use);
                        }
                        else curr[j][ability]=ability_not_use;
                    }
                    else curr[j][ability]=ability_not_use;
                }
            }
        }
        if(i!=0){
            for(int j=0;j<n;j++) prev[j]=curr[j];
        }
    }
    return curr[0][2];
}