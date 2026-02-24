#include<bits/stdc++.h>
using namespace std;

/*
Question 1:
Given a tree in which a node represents a manager for all subordinates in its subtree. Node stores the salary of that employee. Count the number of managers who were underpaid. i.e average salary of subordinates in its subtree is greater than salary of that manager.
First follow up:
Try to use O(1) space instead of O(n)
Give the minimum amount of money required to satisfy all underpaid managers.
Second follow-up:
Instead of average, if the median of subordinates is greater than manager’s salary then manager is said to be underpaid.
*/
/*
        1
       / \
      2   3
     / \   \
    4   5   6
*/


//make a function returning number of underpaid managers and minimum amount of money required to satisfy all underpaid managers
pair<int,double> underpaid_managers(vector<vector<int>>& tree,vector<double>& salary,int head){
    int manager=head;
    int num_underpaid=0;
    double money_needed=0;
    pair<double,int> underpaid_info=manage_recursive(manager,tree,salary,num_underpaid,money_needed);
    pair<int,double> underpaid_answer=make_pair(num_underpaid,money_needed);
    return underpaid_answer;
}

pair<double,int> manage_recursive(int manager,vector<vector<int>>& tree,vector<double>& salary,int& num_underpaid,double& money_needed){ //sum of salaries of all nodes under it and including itself, number of nodes under it, including it
    if(tree[manager].size()==0){ //leaf node
        pair<double,int> p=make_pair(salary[manager],1);
        return p;
    }
    double total_salary=0;
    int num_nodes=0;
    for(int child:tree[manager]){
        pair<double,int> p=manage_recursive(child,tree,salary,num_underpaid,money_needed);
        total_salary+=p.first;
        num_nodes+=p.second;
    }
    total_salary+=salary[manager];
    num_nodes++;
    if((double)total_salary/num_nodes>(double)salary[manager]){
        num_underpaid++;
        money_needed+=(((double)total_salary/num_nodes)-salary[manager]);
    }
    pair<double,int> ans=make_pair(total_salary,num_nodes);
    return ans;
}

//median
double find_median(vector<double>& arr){
    int n=arr.size();
    if(n%2==1){
        nth_element(arr.begin(),arr.begin()+n/2,arr.end());
        return arr[n/2];
    }
    else{
        nth_element(arr.begin(),arr.begin()+n/2,arr.end());
        double high=arr[n/2];
        nth_element(arr.begin(),arr.begin()+(n-1)/2,arr.end());
        double low=arr[(n-1)/2];
        return (high+low)/2;
    }
}

pair<int,double> underpaid_managers(vector<vector<int>>& tree,vector<double>& salary,int head){
    int manager=head;
    int num_underpaid=0;
    double money_needed=0;
    pair<double,int> underpaid_info=manage_recursive(manager,tree,salary,num_underpaid,money_needed);
    pair<int,double> underpaid_answer=make_pair(num_underpaid,money_needed);
    return underpaid_answer;
}
//make a list of all salaries stored of subordinates
int manage_recursive(int manager,vector<vector<int>>& tree,vector<double>& salary,int& num_underpaid,double& money_needed
,vector<double>& sub_ordinate_salaries,vector<int>& num_sub_ordinates){ //returns number of nodes under it
    if(tree[manager].size()==0){
        sub_ordinate_salaries.clear();
        num_sub_ordinates[manager]=0;
        return 0;
    }
    double total_salary=0;
    int num_nodes=0;
    for(int child:tree[manager]){
        pair<double,int> p=manage_recursive(child,tree,salary,num_underpaid,money_needed);
        total_salary+=p.first;
        num_nodes+=p.second;
    }
    total_salary+=salary[manager];
    num_nodes++;
    if((double)total_salary/num_nodes>(double)salary[manager]){
        num_underpaid++;
        money_needed+=(((double)total_salary/num_nodes)-salary[manager]);
    }
    pair<double,int> ans=make_pair(total_salary,num_nodes);
    return ans;
}
/*
Question2:
Only 5 minutes were left, interviewer just wanted the approach of the problem.
Given a classroom of size N x M, in which an exam is being conducted, the probability of
passing a chit without being caught between any two adjacent horizontal and vertical cell is given. Given the source and destination, find the maximum probability with which a chit could be passed along any valid path.
*/